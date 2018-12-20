//
// Created by Tomer Yona on 2018-12-20.
//

#include "Plus.h"


Plus::Plus(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

double Plus::calculate() {
    return left->calculate()+right->calculate();
}


