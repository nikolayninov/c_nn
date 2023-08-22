#include "Sin.hpp"

Sin::Sin()
{
    func res = [](double xx)
    {
        return sin(xx);
    };
    func grad = [](double xx)
    {
        return cos(xx);
    };
    sfunc strng = []()
    {
        return "sin(x)";
    };

    this->setFunc(res);
    this->setGradient(grad);
    this->setStringifier(strng);
}
Sin::~Sin() {}