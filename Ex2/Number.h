#pragma once
#include "Expression.h"

class Number : public Expression
{
private:
    double value;

public:
    Number(const double value = 0) : value(value)
    {
    }

    double calculate()
    {
        return value;
    }
};
