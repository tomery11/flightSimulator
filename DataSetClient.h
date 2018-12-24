//
// Created by t on 22/12/18.
//

#ifndef FLIGHTSIMULATOR_DATASETCLIENT_H
#define FLIGHTSIMULATOR_DATASETCLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <string>
#include "SymbolsTable.h"

using namespace std;

class DataSetClient {
    int sockfd;
public:
    DataSetClient(string ipAddress, int port, SymbolsTable *symbols);
    ~DataSetClient();
};


#endif //FLIGHTSIMULATOR_DATASETCLIENT_H
