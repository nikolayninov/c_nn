#include "../../include/cnn/Layers/Input.hpp"

Input::Input()
{
}
Input::Input(int layer_size) : Layer(layer_size, nullptr)
{
    this->setA(Matrix::Ones(1, layer_size));
}

void Input::forward(Matrix a, int lo, int hi)
{
    this->setA(a);
}
void Input::build(Layer *l, int layer_num)
{
}

void Input::call(Matrix a)
{
}

std::string Input::get_config()
{
    return "";
}
void Input::loadLayer(std::ifstream &f)
{
    int layer_size;
    f >> layer_size;
    this->setLayerSize(layer_size);
    this->setA(readMatrix(f));
}
void Input::saveLayer(std::ofstream &f)
{
    f << "Input\n";
    f << this->getLayerSize() << '\n';
    writeMatrix(this->getA(), f);
}