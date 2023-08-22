#include "Cos.hpp"

Cos::Cos()
{
    func res = [](double xx)
    {
        return cos(xx);
    };
    func grad = [](double xx)
    {
        return -sin(xx);
    };
    sfunc strng = []()
    {
        return "cos(x)";
    };

    this->setFunc(res);
    this->setGradient(grad);
    this->setStringifier(strng);
}
Cos::~Cos() {}