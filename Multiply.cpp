//
// Created by Tomer Yona on 2018-12-20.
//

#include "Multiply.h"

Multiply::Multiply(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

double Multiply::calculate() {
    return left->calculate()*right->calculate();
}
