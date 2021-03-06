//
// Created by Tomer Yona on 2018-12-22.
//

#ifndef FLIGHTSIMULATOR_CONDITIONPARSER_H
#define FLIGHTSIMULATOR_CONDITIONPARSER_H

#include "Command.h"
#include "ParseUtils.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include "ShuntingYard.h"

class ParseUtils;
class ConditionParser : public Command {

    virtual void doCommand(std::vector<string> *inputVec)=0;

protected:
    ParseUtils *parseUtils1;
    //vector<Command *> commands;
    vector<string> lineCommandsVec;
    string firstExp;
    string secondExp;
    ShuntingYard myAlgo;
    //Expression *leftExpr;
    //Expression *rightExpr;
    string condition_opr;
    SymbolsTable *symbolsTable;

public:

    void set(vector<string> *inputVec);
    bool meetsCondition();
    void doTheCommands();
    void setSymbolTable(SymbolsTable *symbolsTable);
    ~ConditionParser();
};


#endif //FLIGHTSIMULATOR_CONDITIONPARSER_H
