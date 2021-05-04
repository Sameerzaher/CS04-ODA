#pragma once
#include"BinaryExpression.h"
class Plus : public BinaryExpression
{
public:
    Plus(Expression* const left, Expression* const right) : BinaryExpression(left,right)
    {

    }
    double calculate()
    {
            return(getL()->calculate()+getR()->calculate());
    }
};