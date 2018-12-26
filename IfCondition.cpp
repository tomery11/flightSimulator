//
// Created by Tomer Yona on 2018-12-22.
//

#include "IfCondition.h"

void IfCondition::doCommand(std::vector<string> *inputVec) {
    set(inputVec);
    if(meetsCondition()) {
        doTheCommands();
    }
}
