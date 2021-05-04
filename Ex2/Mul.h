#pragma once
#include "BinaryExpression.h"
class Mul : public BinaryExpression
{
public:
    Mul(Expression *const left, Expression *const right) : BinaryExpression(left, right)
    {
    }
    double calculate()
    {
        return (getL()->calculate() * getR()->calculate());
    }
};