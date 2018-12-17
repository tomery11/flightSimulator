//
// Created by tomer on 12/16/18.
//

#ifndef FLIGHTSIMULATOR_COMMAND_H
#define FLIGHTSIMULATOR_COMMAND_H

#include <string>
#include <vector>
using namespace std;

class Command {
public:
    virtual void doCommand(std::vector<string> *inputVec)=0;
};


#endif //FLIGHTSIMULATOR_COMMAND_H
