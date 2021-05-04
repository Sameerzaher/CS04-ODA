#pragma once
#include "BinaryExpression.h"
class Minus : public BinaryExpression
{
public:
    Minus(Expression *const left, Expression *const right) : BinaryExpression(left, right)
    {
    }
    double calculate()
    {
        return (getL()->calculate() - getR()->calculate());
    }
};