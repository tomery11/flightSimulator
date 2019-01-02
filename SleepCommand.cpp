//
// Created by t on 22/12/18.
//

#include "SleepCommand.h"
#include "ShuntingYard.h"
#include <thread>
#include <chrono>

void SleepCommand::doCommand(std::vector<string> *inputVec) {
    //there is no stou function
    ShuntingYard myAlgo;
    long int millisec = (long int) myAlgo.evaluate(inputVec->at(1), this->symbolTable);
    //cout << "sleep is working " << milisec << endl;
    //sleep(millisec / 1000);
    this_thread::sleep_for(chrono::milliseconds(millisec));
}

void SleepCommand::setSymbolTable(SymbolsTable *symbolTable) {
    this->symbolTable = symbolTable;
}


