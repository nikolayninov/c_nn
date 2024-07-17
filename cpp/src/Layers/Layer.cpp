#include "../../include/cnn/Layers/Layer.hpp"
#include "../../include/cnn/Initializers.hpp"

#include <iostream>

Layer::Layer()
{
}
Layer::Layer(int layer_size, Function *activation)
{
    this->layer_num = 0;
    this->layer_size = layer_size;

    this->a = Matrix::Zero(1, layer_size);
    this->z = Matrix::Zero(0, 0);
    this->b = Matrix::Zero(0, 0);
    this->w = Matrix::Zero(0, 0);

    this->activation = activation;
}
Layer::Layer(Layer &&rhs)
{
    this->layer_num = rhs.getLayerNum();
    this->layer_size = rhs.getLayerSize();
    this->a = rhs.getA();
    this->z = rhs.getZ();
    this->b = rhs.getB();
    this->w = rhs.getW();
    this->activation = rhs.getActivation();
}

Matrix &Layer::getA()
{
    return this->a;
}
void Layer::setA(Matrix a)
{
    this->a = a;
}

Matrix &Layer::getZ()
{
    return this->z;
}
void Layer::setZ(Matrix z)
{
    this->z = z;
}

Matrix &Layer::getB()
{
    return this->b;
}
void Layer::setB(Matrix b)
{
    this->b = b;
}

Matrix &Layer::getW()
{
    return this->w;
}
void Layer::setW(Matrix w)
{
    this->w = w;
}

Function *Layer::getActivation()
{
    return this->activation;
}
void Layer::setActivation(Function *f)
{
    this->activation = f;
}

Layer *Layer::getL()
{
    return this->l;
}

void Layer::setL(Layer *l)
{
    this->l = l;
}

bool Layer::isBuilt()
{
    return this->built;
}
void Layer::setIsBuilt(bool b)
{
    this->built = b;
}

int Layer::getLayerNum()
{
    return this->layer_num;
}
void Layer::setLayerNum(int n)
{
    this->layer_num = n;
}

int Layer::getLayerSize()
{
    return this->layer_size;
}
void Layer::setLayerSize(int n)
{
    this->layer_size = n;
}

void Layer::forward(Matrix a, int lo, int hi)
{
    this->setA(a);
}

void Layer::build(Layer *l, int layer_num)
{
    this->setIsBuilt(true);
    std::cout << "Layer" << std::endl;
}

void Layer::call(Matrix)
{
}

void Layer::loadLayer(std::ifstream &f)
{
}
void Layer::saveLayer(std::ofstream &f)
{
}