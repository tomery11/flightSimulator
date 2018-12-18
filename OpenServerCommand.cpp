//
// Created by tomer on 12/16/18.
//

#include "OpenServerCommand.h"

void OpenServerCommand::doCommand(std::vector<string> *inputVec) {
    //input validation

    this->port = stoi(inputVec->at(1));
    this->frequency = stoi(inputVec->at(2));
    //open thread and read a line in frequency, update symbol table
    pthread_t threadID;
    struct ServerData serverData;
    serverData.port = this->port;
    serverData.frequency = this->frequency;
    //wont run if symbolTable is NULL
    if (this->symbolTable == NULL) {
        throw "can not start server thread, bad pointer to symbol Table";
    }
    serverData.symbolTable = this->symbolTable;
    int rc = pthread_create(&threadID, NULL, thread_func, (void *)&serverData);
}

void OpenServerCommand::setSymbolTable(SymbolsTable *symbolTable) {
    this->symbolTable = symbolTable;
}


//run in the thread. open a a dataReaderServer and in an infinite loop update the symbol table
//argument: ServerData struct with 0.int port 1.int frequency 2.pointer to symbolTable
void* thread_func(void *serverData) {
    //serverData is of type ServerData
    struct ServerData *serverData1;
    serverData1 = (struct ServerData *) serverData;
    //open the server
    DataReaderServer server(serverData1->port, serverData1->frequency);
    //infinite loop with updates for symbolTable
    while (true) {
        server.update(serverData1->symbolTable);
    }
    //return nullptr;
}
