//
// Created by t on 22/12/18.
//

#include "SleepCommand.h"

void SleepCommand::doCommand(std::vector<string> *inputVec) {
    //there is no stou function
    ShuntingYard myAlgo;
    unsigned int milisec = myAlgo.evaluate(inputVec->at(1));

    sleep(milisec / 1000);
}
