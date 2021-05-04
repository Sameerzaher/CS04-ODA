
#include <iostream>
#include "Number.h"
#include "Plus.h"
#include "Minus.h"
#include "Div.h"
#include "Mul.h"

using namespace std;

int main()
{
    //init
    Expression *result;
    Expression *First;
    Expression *Second;
    Expression *Third;
    Expression *Fourth;
    Expression *Fifth;
    First = new Number(67);
    Second = new Number(34);
    Third = new Number(9);
    Fourth = new Number(8);
    Fifth = new Number(7);
    //the equation
    result = new Plus(new Div(First, Second), new Mul(Third, new Minus(Fourth, Fifth)));
    cout << result->calculate();
    cin.get();
    return 0;
}