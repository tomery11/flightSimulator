//
// Created by t on 23/12/18.
//

#ifndef FLIGHTSIMULATOR_ENTERC_H
#define FLIGHTSIMULATOR_ENTERC_H
#include "Command.h"
#include <iostream>
#include <stdio.h>

class EntercCommand : public Command {
    virtual void doCommand(std::vector<string> *inputVec);
    void setSymbolTable(SymbolsTable *symbols);
};


#endif //FLIGHTSIMULATOR_ENTERC_H
