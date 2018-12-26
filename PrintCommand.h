//
// Created by t on 22/12/18.
//

#ifndef FLIGHTSIMULATOR_PRINTCOMMAND_H
#define FLIGHTSIMULATOR_PRINTCOMMAND_H

#include "Command.h"
#include <iostream>
#include "SymbolsTable.h"

class PrintCommand : public Command {
    SymbolsTable *symbols;
public:
    PrintCommand(SymbolsTable *symbols);
    virtual void doCommand(std::vector<string> *inputVec);
    void setSymbolTable(SymbolsTable *symbols);
};


#endif //FLIGHTSIMULATOR_PRINTCOMMAND_H
