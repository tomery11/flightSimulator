//
// Created by Tomer Yona on 2018-12-21.
//

#ifndef FLIGHTSIMULATOR_COMMANDEXPRESSION_H
#define FLIGHTSIMULATOR_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
#include <vector>
#include <string>
using namespace std;

class CommandExpression : public Expression {
public:
    Command *c;
    vector<string> *parameters;
public:
    explicit CommandExpression(Command *c, std::vector<string> *parameters);

    double calculate() override;


};


#endif //FLIGHTSIMULATOR_COMMANDEXPRESSION_H
