

#ifndef FLIGHTSIMULATOR_VARCOMMAND_H
#define FLIGHTSIMULATOR_VARCOMMAND_H

#include "Command.h"
class VarCommand: public Command {
    string name;
    int value;
public:
    void doCommand(std::vector<string> inputVec);
};


#endif //FLIGHTSIMULATOR_VARCOMMAND_H
//