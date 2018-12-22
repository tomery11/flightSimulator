//
// Created by t on 22/12/18.
//

#include "DataSetClient.h"

DataSetClient::DataSetClient(string ipAddress, int port, SymbolsTable *symbols) {
    try {

        int sockfd, portno;
        ssize_t n;
        struct sockaddr_in serv_addr;
        struct hostent *server;

        char buffer[256];

        /* Create a socket point */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            throw "socket creation failed";
        }

        server = gethostbyname(ipAddress.c_str());

        if (server == NULL) {
            throw "bad host name";
        }

        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons((uint16_t)port);

        /* Now connect to the server */
        if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
            throw "bad connection";
        }
        //loop to send to simulator
        while (true) {
            cout << "client loop" << endl;
            //get a message for the simulator
            pair<string, double> message = symbols->getMessage();
            //check validity and send if real message
            if (!(message.first == "0" && message.second == 0)) {
                memset(buffer, 0, 256);
                string str = message.first + ' ' + to_string(message.second);
                strcpy(buffer, str.c_str());
                /* Send message to the server */
                n = write(sockfd, buffer, strlen(buffer));

                if (n < 0) {
                    throw "write to socket failed";
                }

                /* todo Now read server response - is needed?*/
                bzero(buffer, 256);
                n = read(sockfd, buffer, 255);

                if (n < 0) {
                    throw "reading from socket failed";
                }
                printf("%s\n", buffer);
            }
        }
    } catch (char *exception) {
        printf("%s",exception);
    }
}
