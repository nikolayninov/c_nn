#include "Pol.hpp"

Pol::Pol(double n) : Function()
{
    this->power = n;

    func res = [this](double xx)
    {
        return pow(xx, power);
        // return 79;
    };

    func grad = [this](double xx)
    {
        return power * pow(xx, power - 1);
    };

    sfunc strng;

    if (n == 1)
        strng = []()
        { return "(x)"; };
    else
        strng = [this]()
        {
            return "(x)^(" + std::to_string(power) + ")";
        };

    this->setFunc(res);
    this->setGradient(grad);
    this->setStringifier(strng);
}
Pol::Pol() : Pol(1) {}

Pol::~Pol() {}

double Pol::getPow()
{
    return this->power;
}
