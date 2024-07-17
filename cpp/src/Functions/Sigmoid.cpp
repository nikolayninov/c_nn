#include "../../include/cnn/Functions/Sigmoid.hpp"

Sigmoid::Sigmoid() : Function()
{
    func res = [&](Scalar xx)
    {
        return 1 / (1 + exp(-xx));
    };
    func grad = [&](Scalar xx)
    {
        return 1 / (1 + exp(-xx)) * (1 - 1 / (1 + exp(-xx)));
    };
    sfunc strng = [&]()
    {
        return "Sigmoid(x)";
    };

    this->setFunc(res);
    this->setGradient(grad);
    this->setStringifier(strng);
}