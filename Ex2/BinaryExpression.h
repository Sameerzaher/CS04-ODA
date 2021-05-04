#pragma once
#include "Expression.h"
class BinaryExpression : public Expression
{
public:
    BinaryExpression(Expression *const left = 0, Expression *const right = 0) : left(left), right(right)
    {
    }
    Expression *getL()
    {
        return left;
    }
    Expression *getR()
    {
        return right;
    }

private:
    Expression *left;
    Expression *right;
};