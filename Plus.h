//
// Created by Tomer Yona on 2018-12-20.
//

#ifndef FLIGHTSIMULATOR_PLUS_H
#define FLIGHTSIMULATOR_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression{
public:
    Plus(Expression *leftExp, Expression *rightExp);
    double calculate();
};


#endif //FLIGHTSIMULATOR_PLUS_H
