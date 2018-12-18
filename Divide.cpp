//
// Created by Tomer Yona on 2018-12-20.
//

#include "Divide.h"

Divide::Divide(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}

double Divide::calculate() {
    return left->calculate()/right->calculate();
}
