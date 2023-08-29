#ifndef LOG_H
#define LOG_H

#include "Function.hpp"

class Log : public Function
{
public:
    Log();
    Log(double);
    ~Log();

    double getBase();

private:
    double base;
};

#endif