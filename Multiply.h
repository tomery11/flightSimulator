//
// Created by Tomer Yona on 2018-12-20.
//

#ifndef FLIGHTSIMULATOR_MULTIPLY_H
#define FLIGHTSIMULATOR_MULTIPLY_H


#include "BinaryExpression.h"

class Multiply : public BinaryExpression{
public:
    Multiply(Expression *leftExp, Expression *rightExp);
    double calculate();
};


#endif //FLIGHTSIMULATOR_MULTIPLY_H
