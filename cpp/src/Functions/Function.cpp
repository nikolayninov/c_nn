#include "../../include/cnn/Functions/Function.hpp"
#include <iostream>

Function::Function()
{
    func res = [this](Scalar xx)
    {
        return -1;
    };

    func grad = [&](Scalar xx)
    {
        return -1;
    };
    sfunc strng = [this]()
    {
        return "!!!";
    };

    this->setFunc(res);
    this->setGradient(grad);
    this->setStringifier(strng);
}

Function::Function(const Function &rhs)
{
    this->setFunc(rhs.getFunc());
    this->setGradient(rhs.getGradient());
    this->setStringifier(rhs.getStringifier());
}
Function::Function(Function &&rhs)
{
    this->setFunc(rhs.getFunc());
    this->setGradient(rhs.getGradient());
    this->setStringifier(rhs.getStringifier());
}
Function Function::operator=(const Function &rhs)
{
    this->setFunc(rhs.getFunc());
    this->setFunc(rhs.getFunc());
    this->setGradient(rhs.getGradient());
    this->setStringifier(rhs.getStringifier());

    return *this;
}
Function::~Function()
{
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
    return this->getStringifier()();
}

Scalar Function::call(Scalar x) const
{
    return this->getFunc()(x);
}

ColVector Function::call(ColVector &x) const
{
    const size_t n = x.size();
    ColVector r(n);
#pragma omp parallel for
    for (size_t i = 0; i < n; ++i)
    {
        r[i] = this->getFunc()(x(i));
    }

    return r;
}

Matrix Function::call(Matrix &x) const
{
    const size_t rows = x.col(0).size();
    const size_t cols = x.row(0).size();
    Matrix r(rows, cols);
#pragma omp parallel for collapse(2)
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            r(i, j) = this->getFunc()(x(i, j));
        }
    }
    return r;
}

Scalar Function::gradAt(Scalar x) const
{
    return this->getGradient()(x);
}

ColVector Function::gradAt(ColVector &x) const
{
    const size_t n = x.size();
    ColVector r(n);
#pragma omp parallel for
    for (size_t i = 0; i < n; ++i)
    {
        r(i) = this->getGradient()(x(i));
    }

    return r;
}

Matrix Function::gradAt(Matrix &x) const
{
    const size_t rows = x.col(0).size();
    const size_t cols = x.row(0).size();
    Matrix r(rows, cols);
#pragma omp parallel for collapse(2)
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            r(i, j) = this->getGradient()(x(i, j));
        }
    }
    return r;
}

std::ostream &operator<<(std::ostream &outs, const Function &f)
{
    return outs << f.to_string();
}

Function operator+(const Function &lhs, const Function &rhs)
{
    Function ff = Function();

    func res = [&](Scalar x)
    {
        return lhs.call(x) + rhs.call(x);
    };

    func grad = [&](Scalar x)
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

Function operator-(const Function &lhs, const Function &rhs)
{
    Function ff = Function();

    func res = [&](Scalar x)
    {
        return lhs.call(x) - rhs.call(x);
    };

    func grad = [&](Scalar x)
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

Function operator*(const Function &lhs, const Function &rhs)
{
    Function ff = Function();

    func res = [&](Scalar x)
    {
        return lhs.call(x) * rhs.call(x);
    };

    func grad = [&](Scalar x)
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

Function operator/(const Function &lhs, const Function &rhs)
{
    Function ff = Function();

    func res = [&](Scalar x)
    {
        return lhs.call(x) / rhs.call(x);
    };

    func grad = [&](Scalar x)
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

Function Function::exponent(const Function &rhs)
{
    Function f = Function();

    func res = [this, &rhs](Scalar x)
    {
        return pow(call(x), rhs.call(x));
    };

    func grad = [this, &rhs](Scalar x)
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
