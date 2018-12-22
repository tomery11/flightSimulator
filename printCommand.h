//
// Created by t on 22/12/18.
//

#ifndef FLIGHTSIMULATOR_PRINTCOMMAND_H
#define FLIGHTSIMULATOR_PRINTCOMMAND_H

#include "Command.h"
#include <iostream>
#include "SymbolsTable.h"

class printCommand : public Command {
    SymbolsTable *symbols;
public:
    printCommand(SymbolsTable *symbols);
    virtual void doCommand(std::vector<string> *inputVec);
};


#endif //FLIGHTSIMULATOR_PRINTCOMMAND_H
