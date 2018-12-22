

#ifndef FLIGHTSIMULATOR_VARCOMMAND_H
#define FLIGHTSIMULATOR_VARCOMMAND_H

#include "Command.h"
#include "SymbolsTable.h"
class VarCommand: public Command {
    string name;
    string bind;
    SymbolsTable *symbols;
public:
    void doCommand(std::vector<string> *inputVec);
    void setSymbols(SymbolsTable *symbols);
};


#endif //FLIGHTSIMULATOR_VARCOMMAND_H
//