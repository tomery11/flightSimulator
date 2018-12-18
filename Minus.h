//
// Created by Tomer Yona on 2018-12-20.
//

#ifndef FLIGHTSIMULATOR_MINUS_H
#define FLIGHTSIMULATOR_MINUS_H


#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression *leftExp, Expression *rightExp);
    double calculate();
};


#endif //FLIGHTSIMULATOR_MINUS_H
