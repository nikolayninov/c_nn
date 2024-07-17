#include "../../include/cnn/Models/Sequential.hpp"
#include <algorithm>
#include <iostream>

Sequential::Sequential() : Model()
{
}

Sequential::Sequential(Scalar alpha) : Model(alpha)
{
}

void Sequential::addLayer(Layer *l)
{
    if (this->layers.size() == 0)
    {
    }
    this->layers.push_back(l);
}

void Sequential::build()
{
    const int num_layers = this->layers.size();
    for (int i = 1; i < num_layers; ++i)
    {
        this->layers[i]->build(layers[i - 1], i);
    }
}

void Sequential::feedForward(int lo, int hi)
{
    const int num_layers = this->layers.size();
    for (int i = 1; i < num_layers; ++i)
    {
        this->layers[i]->forward(this->inpt, lo, hi);
    }
}

void Sequential::backPropagate(int lo, int hi)
{
    const int num_layers = this->layers.size();

    Layer *output_layer = this->layers[num_layers - 1];

    std::vector<Matrix> deltas(num_layers);
    for (int i = 0; i < num_layers; ++i)
    {
        deltas[i] = Matrix::Zero(hi - lo, this->layers[i]->getLayerSize());
    }
    for (int i = lo; i < hi; ++i)
    {
        ColVector tmp = output_layer->getA().row(i) - this->gt.row(i);
        ColVector tmp3 = output_layer->getZ().row(i);
        ColVector tmp2 = output_layer->getActivation()->gradAt(tmp3);
        deltas[num_layers - 1].row(i - lo) = tmp.cwiseProduct(tmp2);
    }

    Layer *current_layer;
    for (int i = num_layers - 2; i >= 1; --i)
    {
        output_layer = this->layers[i + 1];
        current_layer = this->layers[i];
        for (int j = lo; j < hi; ++j)
        {
            ColVector tmp = deltas[i + 1].row(j - lo) * (output_layer->getW());
            ColVector tmp3 = current_layer->getZ().row(j);
            ColVector tmp2 = output_layer->getActivation()->gradAt(tmp3);
            deltas[i].row(j - lo) = tmp.cwiseProduct(tmp2);
        }
    }

    for (int i = num_layers - 1; i >= 1; --i)
    {
        output_layer = this->layers[i];
        current_layer = this->layers[i - 1];

        ColVector b_delta = ColVector::Zero(output_layer->getLayerSize());
        Matrix w_delta = Matrix::Zero(output_layer->getLayerSize(), current_layer->getLayerSize());

        for (int j = lo; j < hi; j++)
        {
            b_delta += deltas[i].row(j - lo);
            w_delta += deltas[i].row(j - lo).transpose() * (current_layer->getA().row(j));
        }
        output_layer->getB() -= ((this->alpha) * b_delta) / (hi - lo);
        output_layer->getW() -= ((this->alpha) * w_delta) / (hi - lo);
    }
}

Scalar Sequential::computeLoss()
{
    Layer *output_layer = this->layers[this->layers.size() - 1];
    Scalar loss = 0;
    for (int i = 0; i < this->inpt.innerSize(); ++i)
    {
        ColVector tmp = (output_layer->getA().row(i)) - this->gt.row(i);
        loss += tmp.dot(tmp) / this->inpt.innerSize();
    }
    return loss;
}

void Sequential::run(Matrix inpt, Matrix gt, int epochs, int minibatch_size)
{
    int m = inpt.innerSize();
    this->inpt = inpt;
    this->gt = gt;
    this->layers[0]->setA(inpt);
    this->build();

    std::vector<Scalar> losses;

    int batches = ceil(double(m) / double(minibatch_size));

    for (int e = 0; e < epochs; ++e)
    {
        for (int i = 0; i < batches; ++i)
        {
            int lo = minibatch_size * i;
            int hi = std::min(minibatch_size * (i + 1), m);

            backPropagate(lo, hi);

            feedForward(lo, hi);
        }
        double loss = computeLoss();

        std::cout << "Epoch #" << e << " --> Total loss: " << loss << std::endl;
        losses.push_back(loss);
    }
}

Matrix Sequential::predict(Matrix data)
{
    const int num_layers = this->layers.size();
    Matrix gt = Matrix::Zero(data.innerSize(), this->layers[num_layers - 1]->getLayerSize());

    const int m = data.innerSize();
    for (int i = 0; i < m; i++)
    {
        ColVector input = data.row(i);
        for (int j = 1; j < num_layers; j++)
        {
            Layer *output_layer = this->layers[j];
            input = (output_layer->getW()) * input + (output_layer->getB());
            input = (output_layer->getActivation())->call(input);
        }
        gt.row(i) = input.transpose();
    }
    return gt;
}