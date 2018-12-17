//
// Created by t on 17/12/18.
//

#ifndef FLIGHTSIMULATOR_CONNECTCOMMAND_H
#define FLIGHTSIMULATOR_CONNECTCOMMAND_H
#include "Command.h"
#include "SymbolsTable.h"
#include <iostream>
#include <pthread.h>
using namespace std;

class ConnectCommand : Command {
    string ip_address;
    int port;
public:
    void doCommand(std::vector<string> *inputVec);
    void* connect(void* arg);
};


#endif //FLIGHTSIMULATOR_CONNECTCOMMAND_H
