//
// Created by t on 17/12/18.
//

#include "ConnectCommand.h"

//run in a seperate thread. a client writing the data on the simulator.
void *ConnectCommand::connect(void *arg) {
    return nullptr;
}

//create a thread and run connect
void ConnectCommand::doCommand(std::vector<string> *inputVec) {
    pthread_t threadID;
    int rc = pthread_create(&threadID, NULL, connect, (void *)inputVec);
}
