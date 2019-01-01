//
// Created by t on 22/12/18.
//

#include <thread>
#include <chrono>
#include "SleepCommand.h"
#include "ShuntingYard.h"


void SleepCommand::doCommand(std::vector<string> *inputVec) {
    //there is no stou function
    ShuntingYard myAlgo;
    unsigned int milisec = (unsigned int)myAlgo.evaluate(inputVec->at(1), this->symbolTable);
    //cout << "sleep is working " << milisec << endl;
    this_thread::sleep_for(chrono::milliseconds(milisec));
}

void SleepCommand::setSymbolTable(SymbolsTable *symbolTable) {
    this->symbolTable=symbolTable;
}


