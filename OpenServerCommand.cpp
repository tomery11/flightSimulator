//
// Created by tomer on 12/16/18.
//

#include "OpenServerCommand.h"

/*the function recieves vector of strings and caculates the 2 arguments since they might be
 * written as mathimatical expression*/
void OpenServerCommand::doCommand(std::vector<string> *inputVec) {
    //input validation
    ShuntingYard myAlgo;
    //todo add another variable in algorithm
    this->port = myAlgo.evaluate(inputVec->at(1),*this->symbolTable);
    this->frequency = myAlgo.evaluate(inputVec->at(2),*this->symbolTable);
    //open thread and read a line in frequency, update symbol table
    pthread_t threadID;
    struct ServerData *serverData = new struct ServerData;
    serverData->port = this->port;
    serverData->frequency = this->frequency;
    //wont run if symbolTable is NULL
    if (this->symbolTable == NULL) {
        throw "can not start server thread, bad pointer to symbol Table";
    }
    serverData->symbolTable = this->symbolTable;
    //start the thread
    int rc = pthread_create(&threadID, NULL, serverThreadFunc, (void *)serverData);
}

void OpenServerCommand::setSymbolTable(SymbolsTable *symbolTable) {
    this->symbolTable = symbolTable;
}


//run in the thread. open a a dataReaderServer and in an infinite loop update the symbol table
//argument: ServerData struct with 0.int port 1.int frequency 2.pointer to symbolTable
void* serverThreadFunc(void *serverData) {
    //serverData is of type ServerData
    struct ServerData *serverData1;
    serverData1 = (struct ServerData *) serverData;
    //open the server, infinite loop with updates for symbolTable
    DataReaderServer server(serverData1->port, serverData1->frequency, serverData1->symbolTable);
    delete(serverData1);
    serverData = NULL;
    return nullptr;
}
