//
// Created by Tomer Yona on 2018-12-22.
//

#ifndef FLIGHTSIMULATOR_LOOPCONDITION_H
#define FLIGHTSIMULATOR_LOOPCONDITION_H


#include "ConditionParser.h"

class LoopCondition : public ConditionParser{
    void doCommand(std::vector<string> *inputVec);
};


#endif //FLIGHTSIMULATOR_LOOPCONDITION_H
