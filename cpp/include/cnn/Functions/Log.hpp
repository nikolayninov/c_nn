#ifndef LOG_H
#define LOG_H

#include "Function.hpp"

class Log : public Function
{
public:
    Log();
    Log(Scalar);
    ~Log();

    Scalar getBase();

private:
    Scalar base;
};

#endif