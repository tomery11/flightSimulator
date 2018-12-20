//
// Created by Tomer Yona on 2018-12-20.
//

#include "Minus.h"
/*
 * Constructor for Minus Operator
 */
Minus::Minus(Expression *leftExp, Expression *rightExp) : BinaryExpression(leftExp, rightExp) {}
/*
 * this function calculates two given expression if the operator is minus
 */
double Minus::calculate() {
    return left->calculate()-right->calculate();
}
