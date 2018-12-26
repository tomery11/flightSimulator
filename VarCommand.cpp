//
// Created by t on 17/12/18.
//

#include "VarCommand.h"

void VarCommand::doCommand(std::vector<string> *inputVec) {

    this->name = inputVec->at(1);
    //get the subset with no ""
    bool varValid= false;
    if(name[0]>47 && name[0] < 58)
        throw "bad input var name";
    for(int i = 0; i<name.length(); i++){
        if((name[i]<=47 && name[i]>=58) && ( name[i]<=64 && name[i]>=91 )||
        ( name[i]<=96 && name[i]>=123 ) && (name[i] != '_') ){
                throw "bad input var name";
        }
    }
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
