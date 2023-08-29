#include "c_nn/Functions/Max.hpp"

Max::Max(const Function lhs, const Function rhs)
{
    func res = [&](double xx)
    {
        double l_val = lhs.call(xx);
        double r_val = rhs.call(xx);

        if (l_val > r_val)
            return l_val;
        else
            return r_val;
    };
    func grad = [&](double xx)
    {
        double l_val = lhs.call(xx);
        double r_val = rhs.call(xx);
        if (l_val > r_val)
            return lhs.gradAt(xx);
        else
            return rhs.gradAt(xx);
    };
    sfunc strng = [&]()
    {
        return "Max(" + lhs.to_string() + ", " + rhs.to_string() + ")";
    };

    this->setFunc(res);
    this->setGradient(grad);
    this->setStringifier(strng);
}

Max::~Max()
{
}