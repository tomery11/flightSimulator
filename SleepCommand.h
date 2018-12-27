//
// Created by t on 22/12/18.
//

#ifndef FLIGHTSIMULATOR_SLEEPCOMMAND_H
#define FLIGHTSIMULATOR_SLEEPCOMMAND_H

#include <unistd.h>
#include "Command.h"

class SleepCommand : public Command {
private:
    SymbolsTable *symbolTable;
public:
    virtual void doCommand(std::vector<string> *inputVec);
    void setSymbolTable(SymbolsTable *symbolTable);
    virtual ~SleepCommand(){}
};


#endif //FLIGHTSIMULATOR_SLEEPCOMMAND_H
