#include "../../include/cnn/Functions/Sin.hpp"

Sin::Sin()
{
    func res = [](Scalar xx)
    {
        return sin(xx);
    };
    func grad = [](Scalar xx)
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