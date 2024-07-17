#include "../../include/cnn/Functions/Log.hpp"

Log::Log(Scalar b) : Function()
{
    this->base = b;

    func res = [this](Scalar xx)
    {
        return log(xx) / log(base);
    };

    func grad = [this](Scalar xx)
    {
        return 1 / (xx * log(base));
    };

    sfunc strng;

    if (b == M_E)

        strng = []()
        { return "ln(x)"; };
    else
        strng = [this]()
        {
            return "log_" + std::to_string(base) + "(x)";
        };

    this->setFunc(res);
    this->setGradient(grad);
    this->setStringifier(strng);
}
Log::Log() : Log(M_E) {}

Log::~Log() {}

Scalar Log::getBase()
{
    return this->base;
}
