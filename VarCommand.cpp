//
// Created by t on 17/12/18.
//

#include "VarCommand.h"
#include "ShuntingYard.h"

void VarCommand::doCommand(std::vector<string> *inputVec) {
    //input validation
    if (this->symbols == NULL) {
        throw "symbols is null";
    }
    this->name = inputVec->at(1);
    if(name[0]>47 && name[0] < 58)
        throw "bad input var name";
    for(unsigned int i = 0; i<name.length(); i++){
        if(((name[i]<=47 && name[i]>=58) && (name[i]<=64 && name[i]>=91))
                ||((name[i]<=96 && name[i]>=123 ) && (name[i] != '_'))){
                throw "bad input var name";
        }
    }
    //add to symbols
    if(inputVec->at(3) == "bind") { //if the var declaration is bind
        //get the subset with no ""
        this->bind = inputVec->at(4).substr(1, inputVec->at(4).length() - 2);
        this->symbols->addVar(this->name, this->bind);
    } else { //no bind
        ShuntingYard shunt;
        double value = shunt.evaluate(inputVec->at(3), symbols);
        this->symbols->addVar(this->name, value);
    }
    //cout << "added var" << endl;
}

void VarCommand::setSymbolTable(SymbolsTable *symbols) {
    this->symbols = symbols;
}

