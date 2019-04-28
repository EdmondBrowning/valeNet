//
// Created by edmond on 18-9-26.
//

#ifndef VTHREAD_VSOCKET_H
#define VTHREAD_VSOCKET_H

#define MAX_MSG_SIZE 4096

#define BUFFER_SIZE 4096

#include <string>
#include <netinet/in.h>

#include "libwilyautoptr.h"
#include "libwilyconnection.h"

namespace wily{
    class VSocket {
    private:
        int sockfd = -1;
        char* address;
        int port = 0;
        struct sockaddr_in ser_addr;
        struct  sockaddr_in client_addr;
    public:
        VSocket(char address[], int port);
        VSocket(std::string, int port);
        void bind();
        void listen(int);
        wily::VAutoPtr<wily::VConnection> accept();
        wily::VAutoPtr<wily::VConnection> connect();
        void close();
        ~VSocket();
    };
}


#endif //VTHREAD_VSOCKET_H
