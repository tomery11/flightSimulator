//
// Created by tomer on 12/16/18.
//

#ifndef FLIGHTSIMULATOR_OPENSERVERCOMMAND_H
#define FLIGHTSIMULATOR_OPENSERVERCOMMAND_H

#include "Command.h"
#include <string>
#include "DataReaderServer.h"
#include <pthread.h>
#include <iostream>
#include "ShuntingYard.h"

//the struct the server thread will get
struct ServerData {
    int port;
    int frequency;
    SymbolsTable *symbolTable;
};

//the server thread function
void* serverThreadFunc(void* serverData);

class OpenServerCommand : public Command {
    int frequency;
    int port;
    SymbolsTable *symbolTable;
public:
    void doCommand(std::vector<string> *inputVec);
    void setSymbolTable(SymbolsTable *symbolTable);
};


#endif //FLIGHTSIMULATOR_OPENSERVERCOMMAND_H
//