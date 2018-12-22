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
        int newSocket, socketDescriptor, n, b;
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
        while (true) {
            cout << "loop " << endl;
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
            //read and update
            memset(buffer, 0, 256);
            n = (int) read(newSocket, buffer, BUFFER_LENGTH);

            if (n < 0) {
                throw "read failed";
            }

            printf("Here is the message: %s\n", buffer);

            /* Write a response to the client */
            //n = write(newsockfd,"I got your message",18);

            //parse
            vector<double> inputVec;
            string digits;
            //go over the input and parse. delimiter is ','
            for(int i = 0; i < BUFFER_LENGTH; i++) {
                //if reached end of a number
                if (buffer[i] == ',') {
                    //if word is not empty, put in the vector
                    if (!digits.empty()) {
                        inputVec.push_back(stod(digits));
                    }
                } else {
                    //if not end of number, add the digit to digits
                    digits += buffer[i];
                }
            }

            for(auto it=inputVec.begin(); it!=inputVec.end(); ++it){
                cout << *it << ' ';
            }
            cout << endl;

            //update the binded vars
        }
    } catch (char *exception) {
        printf("%s",exception);
    }
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

    valread = (int)read(new_socket, buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");

}

