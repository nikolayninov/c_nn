#include "../../include/cnn/Functions/Constant.hpp"

Constant::Constant(Scalar x) : Function()
{
    this->val = x;
    func res = [this](Scalar xx)
    {
        return val;
    };

    func grad = [&](Scalar xx)
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

Scalar Constant::getVal()
{
    return this->val;
}