//
// Created by Tomer Yona on 2018-12-22.
//

#ifndef FLIGHTSIMULATOR_CONDITIONPARSER_H
#define FLIGHTSIMULATOR_CONDITIONPARSER_H


#include "Command.h"
#include "Expression.h"
#include <vector>
#include "parse_utils.h"
#include <iostream>
#include <sstream>
#include <iterator>

class ConditionParser : public Command {

    virtual void doCommand(std::vector<string> *inputVec)=0;

protected:
    vector<Command *> commands;
    vector<string> commandsVec;
    Expression *leftExpr;
    Expression *rightExpr;
    string condition_opr;

public:
    void set(vector<string> *inputVec);
    bool meetsCondition();


};


#endif //FLIGHTSIMULATOR_CONDITIONPARSER_H
