//
// Created by Tomer Yona on 2018-12-19.
//

#ifndef FLIGHTSIMULATOR_EXPRESSION_H
#define FLIGHTSIMULATOR_EXPRESSION_H


class Expression {
public:
    //Expression();
    virtual double calculate()=0;
    virtual ~Expression(){};
};


#endif //FLIGHTSIMULATOR_EXPRESSION_H
