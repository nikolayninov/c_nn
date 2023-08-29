#include "c_nn/Functions/Function.hpp"
#include <iostream>

Function::Function()
{
}
Function::Function(const Function &rhs)
{
    std::cout << "COPY" << std::endl;
    this->setFunc(rhs.getFunc());
    this->setGradient(rhs.getGradient());
    this->setStringifier(rhs.getStringifier());
}
Function::Function(Function &&rhs)
{
    std::cout << "MOVE" << std::endl;
    this->setFunc(rhs.getFunc());
    this->setGradient(rhs.getGradient());
    this->setStringifier(rhs.getStringifier());
}
Function::~Function()
{
    std::cout << "~Function" << std::endl;
}

void Function::setFunc(const func ff)
{
    this->f = ff;
}

func Function::getFunc() const
{
    return this->f;
}

void Function::setGradient(const func g)
{
    this->grad = g;
}

func Function::getGradient() const
{
    return this->grad;
}

void Function::setStringifier(const sfunc st)
{
    this->stringifier = st;
}
sfunc Function::getStringifier() const
{
    return this->stringifier;
}

std::string Function::to_string() const
{
    return this->stringifier();
}

double Function::call(double x) const
{
    return this->f(x);
}
double Function::gradAt(double x) const
{
    return this->grad(x);
}

// double Function::operator()(double x)
// {
//     return this->f(x);
// }

std::ostream &operator<<(std::ostream &outs, const Function &f)
{
    return outs << f.to_string();
}

Function operator+(const Function lhs, const Function rhs)
{
    Function ff = Function();

    func res = [&](double x)
    {
        return lhs.call(x) + rhs.call(x);
    };

    func grad = [&](double x)
    {
        return lhs.gradAt(x) + rhs.gradAt(x);
    };
    sfunc strng = [&]()
    {
        return " (" + lhs.to_string() + "+" + rhs.to_string() + ") ";
    };

    ff.setFunc(res);
    ff.setGradient(grad);
    ff.setStringifier(strng);

    return ff;
}

Function operator-(const Function lhs, const Function rhs)
{
    Function ff = Function();

    func res = [&](double x)
    {
        return lhs.call(x) - rhs.call(x);
    };

    func grad = [&](double x)
    {
        return lhs.gradAt(x) - rhs.gradAt(x);
    };
    sfunc strng = [&]()
    {
        return " (" + lhs.to_string() + "-" + rhs.to_string() + ") ";
    };

    ff.setFunc(res);
    ff.setGradient(grad);
    ff.setStringifier(strng);

    return ff;
}

Function operator*(const Function lhs, const Function rhs)
{
    Function ff = Function();

    func res = [&](double x)
    {
        return lhs.call(x) * rhs.call(x);
    };

    func grad = [&](double x)
    {
        return lhs.gradAt(x) * rhs.call(x) + lhs.call(x) * rhs.gradAt(x);
    };
    sfunc strng = [&]()
    {
        return " [" + lhs.to_string() + "*" + rhs.to_string() + "] ";
    };

    ff.setFunc(res);
    ff.setGradient(grad);
    ff.setStringifier(strng);

    return ff;
}

Function operator/(const Function lhs, const Function rhs)
{
    Function ff = Function();

    func res = [&](double x)
    {
        return lhs.call(x) / rhs.call(x);
    };

    func grad = [&](double x)
    {
        return (lhs.gradAt(x) * rhs.call(x) - lhs.call(x) * rhs.gradAt(x)) / pow(rhs.call(x), 2);
    };
    sfunc strng = [&]()
    {
        return " {" + lhs.to_string() + "}/{" + rhs.to_string() + "} ";
    };

    ff.setFunc(res);
    ff.setGradient(grad);
    ff.setStringifier(strng);

    return ff;
}

Function Function::exp(const Function rhs)
{
    Function f = Function();

    func res = [this, &rhs](double x)
    {
        return pow(call(x), rhs.call(x));
    };

    func grad = [this, &rhs](double x)
    {
        return pow(call(x), rhs.call(x)) * (gradAt(x) * rhs.call(x) / call(x) + rhs.gradAt(x) * log(call(x)));
    };
    sfunc strng = [this, &rhs]()
    {
        return to_string() + "^" + rhs.to_string();
    };

    f.setFunc(res);
    f.setGradient(grad);
    f.setStringifier(strng);

    return f;
}
