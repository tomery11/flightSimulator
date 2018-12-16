//
// Created by tomer on 12/16/18.
//

#ifndef FLIGHTSIMULATOR_DATAREADERSERVER_H
#define FLIGHTSIMULATOR_DATAREADERSERVER_H


#include "Command.h"
#include <string>

class DataReaderServer : Command {
    int frequency;
    int port;
public:
    void doCommand(std::vector<string> inputVec);
};


#endif //FLIGHTSIMULATOR_DATAREADERSERVER_H
