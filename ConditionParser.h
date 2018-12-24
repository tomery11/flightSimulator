//
// Created by Tomer Yona on 2018-12-22.
//

#ifndef FLIGHTSIMULATOR_CONDITIONPARSER_H
#define FLIGHTSIMULATOR_CONDITIONPARSER_H


#include "Command.h"
#include "Expression.h"
#include <vector>

class ConditionParser : public Command {

    virtual void doCommand(std::vector<string> *inputVec)=0;

protected:
    vector<Command *> commands;
    Expression *leftExpr;
    Expression *rightExpr;
    string condition_opr;

public:
    void set(Expression *leftExpr, Expression *rightExpr, string condition_opr);
    bool meetsCondition();


};


#endif //FLIGHTSIMULATOR_CONDITIONPARSER_H
