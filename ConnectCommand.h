//
// Created by t on 17/12/18.
//

#ifndef FLIGHTSIMULATOR_CONNECTCOMMAND_H
#define FLIGHTSIMULATOR_CONNECTCOMMAND_H

#include "Command.h"
#include "SymbolsTable.h"
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include "DataSetClient.h"
#include "SymbolsTable.h"

using namespace std;

//the struct the client thread will get
struct ClientData {
    string ipAddress;
    int port;
    SymbolsTable *symbolTable;
};

//the server thread function
void* clientThreadFunc(void* clientData);

class ConnectCommand : public Command {
    string ipAddress;
    int port;
    SymbolsTable *symbolTable;
public:
    void doCommand(std::vector<string> *inputVec);
    void setSymbolTable(SymbolsTable *symbolTable);
};


#endif //FLIGHTSIMULATOR_CONNECTCOMMAND_H
