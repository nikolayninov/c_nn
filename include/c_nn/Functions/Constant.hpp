#ifndef CONSTANT_H
#define CONSTANT_H

#include "Function.hpp"

class Constant : public Function
{
public:
    Constant();
    Constant(double);
    ~Constant();

    double getVal();

private:
    double val;
};

#endif