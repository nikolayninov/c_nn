#include "../../include/cnn/Functions/Pol.hpp"

Pol::Pol(Scalar n) : Function()
{
    this->power = n;

    func res = [this](Scalar xx)
    {
        return pow(xx, this->power);
        // return 79;
    };

    func grad = [&](Scalar xx)
    {
        return power * pow(xx, this->power - 1);
    };

    sfunc strng;

    if (n == 1)
        strng = [&]()
        { return "(x)"; };
    else
        strng = [&]()
        {
            return "(x)^(" + std::to_string(this->power) + ")";
        };

    this->setFunc(res);
    this->setGradient(grad);
    this->setStringifier(strng);
}
Pol::Pol() : Pol(1) {}

Pol::~Pol() {}

Scalar Pol::getPow()
{
    return this->power;
}
