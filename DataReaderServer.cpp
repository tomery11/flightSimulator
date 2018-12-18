//
// Created by Tomer Yona on 2018-12-19.
//

#include "DataReaderServer.h"

DataReaderServer::DataReaderServer(int port, int frequency) {
    this->port = port;
    this->frequency = frequency;
    char buffer[256];
    int newSocket, socketDescriptor, n;
    //create socket
    socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketDescriptor == 0) {
        throw "server secket creation failed";
    }
    //create address structure for bind
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    address.sin_family = AF_INET; //tcp
    address.sin_addr.s_addr = INADDR_ANY; //127.0.0.1 = self
    address.sin_port = htons( (uint16_t)this->port);
    //bind socket to port and ip address
    if (bind(socketDescriptor, (struct sockaddr *)&address,sizeof(address)) < 0) {
        throw "server could not bind";
    }
    //listen
    if (listen(socketDescriptor, this->frequency) < 0) {
        throw "server listen failed";
    }
    //accept
    newSocket = accept(socketDescriptor, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if(newSocket < 0) {
        throw "server accept failed";
    }
    //read and update
    memset(buffer, 0, 256);
    n = (int)read( newSocket,buffer,255 );

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Here is the message: %s\n",buffer);

    /* Write a response to the client */
    //n = write(newsockfd,"I got your message",18);

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    //parse
    //update the binded vars


}

//update the symbol table
void DataReaderServer::update(SymbolsTable *symbolTable) {

    //create server
    int server_fd, new_socket, valread;
    struct sockaddr_in address;


    char buffer[1024] = {0};

    char *hello;// = "Hello from server";
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( this->port );

    // Forcefully attaching socket to the port 8080
    bind(server_fd, (struct sockaddr *)&address,sizeof(address));
    this->server_fd = server_fd;

    listen(server_fd, 5);

    // accepting a client
    new_socket = accept(server_fd, (struct sockaddr *)&address,
                        (socklen_t*)&addrlen);

    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");

}

