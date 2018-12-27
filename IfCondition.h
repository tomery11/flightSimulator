//
// Created by Tomer Yona on 2018-12-22.
//

#ifndef FLIGHTSIMULATOR_IFCONDITION_H
#define FLIGHTSIMULATOR_IFCONDITION_H


#include "ConditionParser.h"

class IfCondition : public ConditionParser {

public:
    void doCommand(std::vector<string> *inputVec);

};


#endif //FLIGHTSIMULATOR_IFCONDITION_H
