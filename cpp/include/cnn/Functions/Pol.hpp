#ifndef POL_H
#define POL_H

#include "Function.hpp"

class Pol : public Function
{
public:
    Pol();
    Pol(Scalar);
    ~Pol();

    Scalar getPow();

private:
    Scalar power;
};

#endif