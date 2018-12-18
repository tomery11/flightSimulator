//
// Created by Tomer Yona on 2018-12-20.
//

#ifndef FLIGHTSIMULATOR_DIVIDE_H
#define FLIGHTSIMULATOR_DIVIDE_H


#include "BinaryExpression.h"

class Divide : public BinaryExpression{
public:
    Divide(Expression *leftExp, Expression *rightExp);
    double calculate();

};


#endif //FLIGHTSIMULATOR_DIVIDE_H
