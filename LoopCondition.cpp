//
// Created by Tomer Yona on 2018-12-22.
//

#include "LoopCondition.h"

void LoopCondition::doCommand(vector<string> *inputVec) {
    set(inputVec);
    unsigned long i;
    while (meetsCondition()) {
        doTheCommands();
    }
    //set()
}
