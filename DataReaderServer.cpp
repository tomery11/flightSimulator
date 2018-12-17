//
// Created by Tomer Yona on 2018-12-19.
//

#include "DataReaderServer.h"

DataReaderServer::DataReaderServer(int port, int frequency) {

}


void DataReaderServer::sendToClient(char *hello) {


    this->port = port;
    this->frequency = frequency;
    //create server
    int server_fd, new_socket, valread;
    struct sockaddr_in address;


    char buffer[1024] = {0};

    //char *hello = "Hello from server";
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

