//
// Created by tomer on 12/16/18.
//

#ifndef FLIGHTSIMULATOR_OPENSERVERCOMMAND_H
#define FLIGHTSIMULATOR_OPENSERVERCOMMAND_H


#include "Command.h"
#include <string>
#include "DataReaderServer.h"
#include <pthread.h>
#include <iostream>
class OpenServerCommand : Command {
    int frequency;
    int port;
public:
    void doCommand(std::vector<string> *inputVec);
};


#endif //FLIGHTSIMULATOR_OPENSERVERCOMMAND_H
//