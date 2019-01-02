//
// Created by Tomer Yona on 2018-12-19.
//

#ifndef FLIGHTSIMULATOR_DATAREADERSERVER_H
#define FLIGHTSIMULATOR_DATAREADERSERVER_H

#include <chrono>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "SymbolsTable.h"
#include <iostream>
#include <vector>
#include <thread>

class DataReaderServer {
int port;
int frequency;
int socketDescriptor, newSocket;
public:
    DataReaderServer(int port, int frequency, SymbolsTable *symbols);
    ~DataReaderServer();
};


#endif //FLIGHTSIMULATOR_DATAREADERSERVER_H
