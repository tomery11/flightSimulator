//
// Created by t on 22/12/18.
//

#include "PrintCommand.h"

PrintCommand::PrintCommand(SymbolsTable *symbols) {
    this->symbols = symbols;
}

//print
void PrintCommand::doCommand(std::vector<string> *inputVec) {
    //if need to print a string(start with "), print it
    if (inputVec->at(1)[0] == '"') {
        cout << inputVec->at(1).substr(1, inputVec->at(1).length() - 2) << endl;
    } else if (this->symbols->exist(inputVec->at(1))) {
        //if need to print a var, print it's value
        this->symbols->getVarValue(inputVec->at(1));
    }
    throw "bad print command";
}

