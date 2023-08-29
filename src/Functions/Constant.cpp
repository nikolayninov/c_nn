#include "c_nn/Functions/Constant.hpp"

Constant::Constant(double x) : Function()
{
    this->val = x;
    func res = [this](double xx)
    {
        return val;
    };

    func grad = [this](double xx)
    {
        return 0;
    };
    sfunc strng = [this]()
    {
        return "(" + std::to_string(val) + ")";
    };

    this->setFunc(res);
    this->setGradient(grad);
    this->setStringifier(strng);
}
Constant::Constant() : Constant(1) {}

Constant::~Constant()
{
}

double Constant::getVal()
{
    return this->val;
}