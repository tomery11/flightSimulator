//
// Created by t on 17/12/18.
//

#include "ConnectCommand.h"
#include "ShuntingYard.h"
#include "DataSetClient.h"


//create a thread and run connect
void ConnectCommand::doCommand(std::vector<string> *inputVec) {
    //input validation
    ShuntingYard myAlgo;
    this->ipAddress = inputVec->at(1);
    this->port = (int)myAlgo.evaluate(inputVec->at(2),this->symbolTable);
    //open thread and read a line in frequency, update symbol table
    pthread_t threadID;
    this->clientData = new struct ClientData;
    clientData->ipAddress = this->ipAddress;
    clientData->port = this->port;
    //wont run if symbolTable is NULL
    if (this->symbolTable == NULL) {
        throw "can not start client thread, bad pointer to symbol Table";
    }
    clientData->symbolTable = this->symbolTable;
    //start the thread
    //int rc = pthread_create(&threadID, NULL, clientThreadFunc, (void *)clientData);
    pthread_create(&threadID, NULL, clientThreadFunc, (void *)clientData);
    //pthread_join(threadID, NULL);
}

void ConnectCommand::setSymbolTable(SymbolsTable *symbolTable) {
    this->symbolTable = symbolTable;
}

ConnectCommand::~ConnectCommand() {
    cout << "connect command quit" << endl;
    delete this->clientData;
    this->clientData = NULL;
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
