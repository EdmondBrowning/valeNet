//
// Created by edmond on 18-10-25.
//

#ifndef WILY_VCONNECTION_H
#define WILY_VCONNECTION_H

#include <string>

#define BUFFER_SIZE 4096

namespace wily {
    class VConnection {
        friend class VSocket;
    private:
        int connid = -1;
        char recvbuf[BUFFER_SIZE];
        explicit VConnection(int);
    public:
        void send(char*);
        void send(std::string);

        char *recv();

        void close();
    };
}


#endif //WILY_VCONNECTION_H
