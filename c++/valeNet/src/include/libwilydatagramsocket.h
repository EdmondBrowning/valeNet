//
// Created by edmond on 18-10-25.
//

#ifndef WILY_VDATAGRAMSOCKET_H
#define WILY_VDATAGRAMSOCKET_H

#include <netinet/in.h>
#include <string>

#define BUFFER_SIZE 4096

namespace wily {
    class VDatagramSocket {
    private:
        int sockfd = -1;
        char* address;
        char recvbuf[BUFFER_SIZE];
        struct sockaddr_in ser_addr;
        struct sockaddr_in client_addr;
        int port = 0;
    public:
        VDatagramSocket(char address[], int port);

        void bind();

        void send(char *);

        char *recv();

        struct sockaddr *getClientAddress();

        void close();

        ~VDatagramSocket();
    };
}


#endif //WILY_VDATAGRAMSOCKET_H
