#include "../../include/cnn/Models/Model.hpp"
#include <iostream>
Model::Model()
{
}

Model::Model(Scalar alpha)
{
    this->alpha = alpha;
}

Model::~Model()
{
}

void Model::build()
{
}
void Model::addLayer(Layer *l)
{
    this->layers.push_back(l);
}

bool Model::isBuilt()
{
    return this->built;
}
void Model::setIsBuilt(bool b)
{
    this->built = b;
}

void Model::feedForward(int lo, int hi)
{
}
void Model::backPropagate(int lo, int hi)
{
}
Scalar Model::computeLoss()
{
    return 0.0;
}
void Model::run(Matrix inpt, Matrix gt, int epochs, int minibatch_size)
{
}
Matrix Model::predict(Matrix inpt)
{
    return Matrix::Zero(inpt.innerSize(), inpt.outerSize());
}
void Model::loadModel(std::string f_name)
{
    std::ifstream f;
    f.open(f_name);
    int n;
    f >> n;
    std::string l_name;
    for (int i = 0; i < n; ++i)
    {
        f >> l_name;
        if (l_name == "Input")
        {
            Input *l = new Input();
            l->loadLayer(f);
            this->layers.push_back(l);
        }
        else
        {
            Dense *l = new Dense();
            l->loadLayer(f);
            this->layers.push_back(l);
        }
    }
    f.close();
}
void Model::saveModel(std::string f_name)
{
    std::ofstream f;
    f.open(f_name);
    const int n = this->layers.size();
    f << n << '\n';
    for (int i = 0; i < n; ++i)
    {
        this->layers[i]->saveLayer(f);
    }
    f.close();
}