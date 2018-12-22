//
// Created by t on 17/12/18.
//

#include "ConnectCommand.h"


//create a thread and run connect
void ConnectCommand::doCommand(std::vector<string> *inputVec) {
    //input validation
    this->ipAddress = inputVec->at(1);
    this->port = stoi(inputVec->at(2));
    //open thread and read a line in frequency, update symbol table
    pthread_t threadID;
    struct ClientData *clientData = new struct ClientData;
    clientData->ipAddress = this->ipAddress;
    clientData->port = this->port;
    //wont run if symbolTable is NULL
    if (this->symbolTable == NULL) {
        throw "can not start client thread, bad pointer to symbol Table";
    }
    clientData->symbolTable = this->symbolTable;
    //start the thread
    int rc = pthread_create(&threadID, NULL, clientThreadFunc, (void *)clientData);
}

void ConnectCommand::setSymbolTable(SymbolsTable *symbolTable) {
    this->symbolTable = symbolTable;
}

//run in the thread. open a a dataSetClient and in an infinite loop set vars on simulator according to script.
//argument: clientData struct with 0.string ipAddress 1.int port 2.pointer to symbolTable
void* clientThreadFunc(void *clientData) {
    //connectDatat is of type ConnectData
    struct ClientData *clientData1;
    clientData1 = (struct ClientData *) clientData;
    //open the client, infinite loop set vars on simulator according to script
    DataSetClient server(clientData1->ipAddress, clientData1->port, clientData1->symbolTable);
    delete(clientData1);
    clientData = NULL;
    return nullptr;
}
