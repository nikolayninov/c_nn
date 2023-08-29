#ifndef POL_H
#define POL_H

#include "Function.hpp"

class Pol : public Function
{
public:
    Pol();
    Pol(double);
    ~Pol();

    double getPow();

private:
    double power;
};

#endif