//
// Created by Tomer Yona on 2018-12-19.
//

#ifndef FLIGHTSIMULATOR_NUMBER_H
#define FLIGHTSIMULATOR_NUMBER_H


#include "Expression.h"

class Number : public Expression {

private:
    double value;
public:
    Number(int value);
    Number(double value);
    double calculate();
};


#endif //FLIGHTSIMULATOR_NUMBER_H
