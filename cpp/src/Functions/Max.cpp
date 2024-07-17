#include "../../include/cnn/Functions/Max.hpp"

Max::Max(const Function lhs, const Function rhs)
{
    func res = [&](Scalar xx)
    {
        Scalar l_val = lhs.call(xx);
        Scalar r_val = rhs.call(xx);

        if (l_val > r_val)
            return l_val;
        else
            return r_val;
    };
    func grad = [&](Scalar xx)
    {
        Scalar l_val = lhs.call(xx);
        Scalar r_val = rhs.call(xx);
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