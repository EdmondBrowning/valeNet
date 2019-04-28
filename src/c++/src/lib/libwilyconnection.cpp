//
// Created by edmond on 18-10-25.
//

#include <sys/socket.h>
#include <cstring>
#include <unistd.h>
#include "../include/libwilyconnection.h"

/**
 * VConnection 构造器
 * @param connid
 */
wily::VConnection::VConnection(int connid) {
    this->connid = connid;
}

/**
 * VConnection 发送信息,会使用构造器中接受道德socketId来发送信息
 * @param msg
 */
void wily::VConnection::send(char *msg) {
    if (connid < 0) {
        throw;
    } else {
        ::send(this->connid, msg, strlen(msg), 0);
    }
}

/**
 * VConnection 发送信息,会使用构造器中接受道德socketId来发送信息
 * @param msg
 */
void wily::VConnection::send(std::string msg) {
    char* msgData = const_cast<char *>(msg.data());
    this->send(msgData);
}

/**
 * VConnection 消息监听，会在这里产生阻塞直到接受到信息
 * @return　char* 收到信息的内容
 */
char *wily::VConnection::recv() {
    if (connid < 0) {
        throw;
    } else {
        ::recv(this->connid, recvbuf, sizeof(recvbuf), 0);
        return recvbuf;
    }
}

/**
 * VConnection关闭操作,会关闭socketId的链接
 */
void wily::VConnection::close() {
    ::close(this->connid);
}

//////缺少析构器
