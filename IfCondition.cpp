//
// Created by Tomer Yona on 2018-12-22.
//

#include "IfCondition.h"

void IfCondition::doCommand(std::vector<string> *inputVec) {
    set(inputVec);
    if(meetsCondition()) {
        for(int i = 0; i < commands.size(); i++){
            //this->commands.at(i)->doCommand(this->commandsInput.at(i));
        }
    }
}
