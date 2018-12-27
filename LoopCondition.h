//
// Created by Tomer Yona on 2018-12-22.
//

#ifndef FLIGHTSIMULATOR_LOOPCONDITION_H
#define FLIGHTSIMULATOR_LOOPCONDITION_H


#include "ConditionParser.h"
#include <vector>


class LoopCondition : public ConditionParser {
public:
    virtual void doCommand(std::vector<string> *inputVec);
};


#endif //FLIGHTSIMULATOR_LOOPCONDITION_H
