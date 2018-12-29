//
// Created by t on 22/12/18.
//

#include "SleepCommand.h"
#include "ShuntingYard.h"


void SleepCommand::doCommand(std::vector<string> *inputVec) {
    //there is no stou function
    ShuntingYard myAlgo;
    unsigned int milisec = myAlgo.evaluate(inputVec->at(1), this->symbolTable);
    cout << "sleep is working " << milisec << endl;
    sleep(milisec / 1000);
}

void SleepCommand::setSymbolTable(SymbolsTable *symbolTable) {
    this->symbolTable=symbolTable;
}


