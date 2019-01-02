//
// Created by Tomer Yona on 2018-12-19.
//

#ifndef FLIGHTSIMULATOR_BINARYEXPRESSION_H
#define FLIGHTSIMULATOR_BINARYEXPRESSION_H
#include "Expression.h"

class BinaryExpression : public Expression {
public:
    Expression *left;
    Expression *right;
public:
    BinaryExpression (Expression *leftExp, Expression *rightExp);
    double calculate()=0;
    ~BinaryExpression();

};


#endif //FLIGHTSIMULATOR_BINARYEXPRESSION_H
