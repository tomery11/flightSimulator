//
// Created by Tomer Yona on 2018-12-19.
//

#ifndef FLIGHTSIMULATOR_VAR_H
#define FLIGHTSIMULATOR_VAR_H
#include <string>
#include "Command.h"
using namespace std;
class var : Command {
string name;
string path;
public:
    virtual void doCommand(std::vector<string> inputVec);
};


#endif //FLIGHTSIMULATOR_VAR_H
