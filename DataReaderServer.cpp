//
// Created by tomer on 12/16/18.
//

#include "DataReaderServer.h"

void DataReaderServer::doCommand(std::vector<string> inputVec) {
    //input validation

    this->port = stoi(inputVec.at(1));
    this->frequency = stoi(inputVec.at(2));
    //open thread and read a line in the required frequency

}