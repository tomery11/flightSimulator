//
// Created by t on 22/12/18.
//

#include "SleepCommand.h"

void SleepCommand::doCommand(std::vector<string> *inputVec) {
    //there is no stou function
    unsigned int milisec = stoul(inputVec->at(1));
    sleep(milisec / 1000);
}
