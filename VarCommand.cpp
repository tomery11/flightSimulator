//
// Created by t on 17/12/18.
//

#include "VarCommand.h"

void VarCommand::doCommand(std::vector<string> inputVec) {
    this->name= inputVec.at(0);
    this->value= stoi(inputVec.at(2));
    //set to simulator
}//