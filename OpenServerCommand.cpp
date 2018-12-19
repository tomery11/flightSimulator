//
// Created by tomer on 12/16/18.
//

#include "OpenServerCommand.h"

void OpenServerCommand::doCommand(std::vector<string> inputVec) {
    //input validation

    this->port = stoi(inputVec.at(1));
    this->frequency = stoi(inputVec.at(2));
    //open thread and read a line in frequency

}


void* OpenServerCommand::thread_func(void* arg)
{
    DataReaderServer server(port, frequency);
    cout << "Thread!" << endl;
    return nullptr;
}

