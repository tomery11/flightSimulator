//
// Created by Tomer Yona on 2018-12-19.
//
#define BUFFER_LENGTH 512

#include "DataReaderServer.h"
#include <chrono>
#include <thread>

DataReaderServer::DataReaderServer(int port, int frequency, SymbolsTable *symbols) {
    try {
        this->port = port;
        this->frequency = frequency;
        char buffer[BUFFER_LENGTH + 1];
        int n, b;
        int opt = 1;
        //create socket
        socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
        if (socketDescriptor == 0) {
            throw "server socket creation failed";
        }
        //allow reuse of address and port
        if (setsockopt(socketDescriptor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) != 0) {
            throw "set socket option failed";
        }
        //create address structure for bind
        struct sockaddr_in address;
        int addrlen = sizeof(address);
        address.sin_family = AF_INET; //tcp
        address.sin_addr.s_addr = INADDR_ANY; //accept all addresses\clients
        address.sin_port = htons((uint16_t) this->port);
        //bind socket to port and ip address
        b = bind(socketDescriptor, (struct sockaddr *) &address, sizeof(address));
        if (b < 0) {
            throw "server could not bind";
        }
        int l = 0;
        l = listen(socketDescriptor, 5);
        if (l < 0) {
            throw "server listen failed";
        }
        //}
        //accept
        //cout << "server try to accept" << endl;
        newSocket = accept(socketDescriptor, (struct sockaddr *) &address, (socklen_t *) &addrlen);
        if (newSocket < 0) {
            throw "server accept failed";
        }
        //cout << "server accepted" <<endl;
        int i = 0;
        while (true) {
            i++;
            //read and update
            memset(buffer, 0, BUFFER_LENGTH);
            n = (int) read(newSocket, buffer, BUFFER_LENGTH);

            if (n < 0) {
                throw "read failed";
            }
            //if(i % 200 == 0) {
            //cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            //printf("%s\n", buffer);
            //cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            //}
            //update the vars
            symbols->updateServer(buffer);
            //sleep for frequency
            //this_thread::sleep_for(chrono::milliseconds(1000 / frequency));
            //sleep(frequency/60);
            //newsockfd.flush();
            /* Write a response to the client */
            //n = write(newsockfd,"I got your message",18);
        }
    } catch (char *exception) {
        printf("%s",exception);
    }
}

DataReaderServer::~DataReaderServer() {
    //cout << "server socket closed" << endl;
    close(this->socketDescriptor);
    close(this->newSocket);
}



