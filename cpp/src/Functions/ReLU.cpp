#include "../../include/cnn/Functions/ReLU.hpp"
ReLU::ReLU() : Function()
{
    func res = [&](Scalar xx)
    {
        if (xx < 0)
        {
            return 0.0;
        }
        else
        {
            return (Scalar)xx;
        }
    };
    func grad = [&](Scalar xx)
    {
        if (xx < 0)
            return 0;
        return 1;
    };
    sfunc strng = [&]()
    {
        return "ReLU(x)";
    };

    this->setFunc(res);
    this->setGradient(grad);
    this->setStringifier(strng);
}