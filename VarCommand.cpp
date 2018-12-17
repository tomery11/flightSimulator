//
// Created by t on 17/12/18.
//

#include "VarCommand.h"

void VarCommand::doCommand(std::vector<string> inputVec) {
    //todo input validation:cant start with a number, no saved words,
    // only english chars, numbers and underscore.
    this->name= inputVec.at(0);
    this->value= stoi(inputVec.at(2));
    //set to simulator
}//