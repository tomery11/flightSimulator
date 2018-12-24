//
// Created by t on 17/12/18.
//

#include "VarCommand.h"

void VarCommand::doCommand(std::vector<string> *inputVec) {
    //todo input validation:cant start with a number, no saved words,
    // only english chars, numbers and underscore.
    this->name = inputVec->at(1);
    //get the subset with no ""
    this->bind = inputVec->at(4).substr(1, inputVec->at(4).length() - 2);
    //add to symbols
    if (this->symbols == NULL) {
        throw "symbols is null";
    }
    this->symbols->addVar(this->name, this->bind);
    cout << "added var" << endl;
}

void VarCommand::setSymbols(SymbolsTable *symbols) {
    this->symbols = symbols;
}
