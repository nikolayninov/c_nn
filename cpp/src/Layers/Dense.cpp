#include "../../include/cnn/Layers/Dense.hpp"

#include "../../include/cnn/Initializers.hpp"
#include <iostream>

Dense::Dense() : Layer()
{
}
Dense::Dense(int layer_size, Function *activation) : Layer(layer_size, activation)
{
}

void Dense::forward(Matrix a, int lo, int hi)
{
    for (int i = lo; i < hi; ++i)
    {
        ColVector tmp = this->getW() * this->getL()->getA().row(i).transpose() + this->getB();
        ColVector tmp2 = (this->getActivation())->call(tmp);
        this->getZ().row(i) = tmp;
        this->getA().row(i) = tmp2;
    }
}

void Dense::build(Layer *l, int layer_num)
{
    this->setL(l);
    int m = l->getA().innerSize();

    this->setLayerNum(layer_num);
    this->setW(Matrix::Zero(this->getLayerSize(), l->getLayerSize()).unaryExpr(&randomWeight));
    this->setB(ColVector::Zero(this->getLayerSize()));

    this->getW() *= sqrt(double(2) / double(l->getLayerSize()));

    this->setZ(Matrix::Zero(m, this->getLayerSize()));
    this->setA(Matrix::Zero(m, this->getLayerSize()));
    for (int i = 0; i < m; ++i)
    {
        ColVector tmp = this->getW() * l->getA().row(i).transpose() + this->getB();
        ColVector tmp2 = this->getActivation()->call(tmp);

        this->getZ().row(i) = tmp;
        this->getA().row(i) = tmp2;
    }
}

void Dense::call(Matrix inpt)
{
}

void Dense::loadLayer(std::ifstream &f)
{
    int layer_size, layer_num;
    std::string activation;
    f >> layer_size >> layer_num;
    f >> activation;
    if (activation == "Sigmoid(x)")
    {
        this->setActivation(new Sigmoid());
    }
    else
    {
        this->setActivation(new ReLU());
    }

    this->setLayerSize(layer_size);
    this->setLayerNum(layer_num);
    this->setA(readMatrix(f));
    this->setZ(readMatrix(f));
    this->setB(readMatrix(f));
    this->setW(readMatrix(f));
}
void Dense::saveLayer(std::ofstream &f)
{
    f << "Dense\n";
    f << this->getLayerSize() << ' ' << this->getLayerNum() << '\n';
    f << this->getActivation()->to_string() << '\n';
    writeMatrix(this->getA(), f);
    writeMatrix(this->getZ(), f);
    writeMatrix(this->getB(), f);
    writeMatrix(this->getW(), f);
}