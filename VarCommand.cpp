//
// Created by t on 17/12/18.
//

#include "VarCommand.h"

void VarCommand::doCommand(std::vector<string> *inputVec) {
    //todo input validation:cant start with a number, no saved words,
    // only english chars, numbers and underscore.
    this->name = inputVec->at(1);
    if(inputVec->at(3) == "bind") { //if the var declaration is bind
        //get the subset with no ""
        this->bind = inputVec->at(4).substr(1, inputVec->at(4).length() - 2);
        this->symbols->addVar(this->name, this->bind);
    } else { //there is no bind
        ShuntingYard shunt;
        double value = shunt.evaluate(inputVec->at(3));
        this->symbols->addVar(this->name, value);
    }
    //add to symbols
    if (this->symbols == NULL) {
        throw "symbols is null";
    }
    cout << "added var" << endl;
}

void VarCommand::setSymbols(SymbolsTable *symbols) {
    this->symbols = symbols;
}
