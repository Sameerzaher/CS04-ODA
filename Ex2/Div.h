#pragma once
#include "BinaryExpression.h"
class Div : public BinaryExpression
{
public:
    Div(Expression *const left, Expression *const right) : BinaryExpression(left, right)
    {
    }
    double calculate()
    {
        return (getL()->calculate() / getR()->calculate());
    }
};