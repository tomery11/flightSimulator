//
// Created by tomer on 12/16/18.
//

#ifndef FLIGHTSIMULATOR_COMMAND_H
#define FLIGHTSIMULATOR_COMMAND_H

#include <string>
#include <vector>
#include "SymbolsTable.h"
using namespace std;

class Command {
public:
    virtual void doCommand(std::vector<string> *inputVec) = 0;
    virtual void setSymbolTable(SymbolsTable *symbolsTable) = 0;
    virtual ~Command();
};

#endif //FLIGHTSIMULATOR_COMMAND_H
