#ifndef CONSTANT_H
#define CONSTANT_H

#include "Function.hpp"

class Constant : public Function
{
public:
    Constant();
    Constant(Scalar);
    ~Constant();

    Scalar getVal();

private:
    Scalar val;
};

#endif