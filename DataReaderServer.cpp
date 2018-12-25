//
// Created by Tomer Yona on 2018-12-19.
//
#define BUFFER_LENGTH 255

#include "DataReaderServer.h"

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
        //infinite loop with updates for symbolTable
        //while (true) {
            //listen
            int l = 0;
            l = listen(socketDescriptor, 5);
            if (l < 0) {
                throw "server listen failed";
            }
            //}
            //accept
            newSocket = accept(socketDescriptor, (struct sockaddr *) &address, (socklen_t *) &addrlen);
            if (newSocket < 0) {
                throw "server accept failed";
            }
            while (true) {
                //read and update
                memset(buffer, 0, 256);
                n = (int) read(newSocket, buffer, BUFFER_LENGTH);

                if (n < 0) {
                    throw "read failed";
                }
                //printf("Here is the message: %s\n", buffer);
                //update the vars
                symbols->updateServer(buffer);
                //sleep for frequency
                sleep(frequency/60);

                /* Write a response to the client */
                //n = write(newsockfd,"I got your message",18);
            }

        //}
    } catch (char *exception) {
        printf("%s",exception);
    }
}

DataReaderServer::~DataReaderServer() {
    close(this->socketDescriptor);
    close(this->newSocket);
}



