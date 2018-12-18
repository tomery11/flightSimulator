//
// Created by Tomer Yona on 2018-12-19.
//

#ifndef FLIGHTSIMULATOR_DATAREADERSERVER_H
#define FLIGHTSIMULATOR_DATAREADERSERVER_H

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "SymbolsTable.h"



class DataReaderServer {
int port;
int frequency;
int server_fd;
public:
    DataReaderServer(int port, int frequency);
    void update(SymbolsTable *symbolTable);
};


#endif //FLIGHTSIMULATOR_DATAREADERSERVER_H
