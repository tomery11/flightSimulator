//
// Created by t on 22/12/18.
//

#ifndef FLIGHTSIMULATOR_SLEEPCOMMAND_H
#define FLIGHTSIMULATOR_SLEEPCOMMAND_H

#include <unistd.h>
#include "Command.h"
#include "ShuntingYard.h"

class SleepCommand : public Command {
    virtual void doCommand(std::vector<string> *inputVec);
};


#endif //FLIGHTSIMULATOR_SLEEPCOMMAND_H
