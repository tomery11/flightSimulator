//
// Created by Tomer Yona on 2018-12-22.
//

#include "LoopCondition.h"

void LoopCondition::doCommand(vector<string> *inputVec) {
    set(inputVec);
    unsigned long i;
    while (meetsCondition()) {
        for(i = 0; i < commands.size(); i++){
            //this->commands.at(i)->doCommand(this->commandsInput.at(i));
        }
    }
    //set()
}
