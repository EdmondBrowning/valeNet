#include <utility>

//
// Created by edmond on 18-9-26.
//

#include <sys/socket.h>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include "../include/libwilysocket.h"

/**
 × VSocket构造器
 * @param address
 * @param port
 */
wily::VSocket::VSocket(char address[], int port) {
    this->address = address;
    this->port = port;
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(this->sockfd<0) {
        fprintf(stderr,"socker Error:%s\n",strerror(errno));
        throw;
    }

    this->ser_addr.sin_family = AF_INET;
    this->ser_addr.sin_port = htons(static_cast<uint16_t>(this->port));
    this->ser_addr.sin_addr.s_addr = ::inet_addr(address);
}

/**
 × VSocket构造器
 * @param address
 * @param port
 */
wily::VSocket::VSocket(std::string address, int port) {
    char* addressData = const_cast<char *>(address.data());
    new (this)VSocket(addressData,port);
}

/**
 * Vsocket绑定将链接转为服务
 */
void wily::VSocket::bind() {
    this->ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(::bind(this->sockfd, (struct sockaddr* ) &ser_addr, sizeof(ser_addr))<0) {
        perror("bind");
        throw;
    }
}

/**
 * 指定监听个数
 * @param backlog
 */
void wily::VSocket::listen(int backlog) {
    if(::listen(this->sockfd,backlog) < 0){
        LOG(ERROR)<<"listen";
        throw;
    }
}

/**
 * 接收函数，会在此处产生阻塞
 * @return
 */
wily::VAutoPtr<wily::VConnection> wily::VSocket::accept(){
    socklen_t length = sizeof(client_addr);
    int conn = ::accept(this->sockfd,(struct sockaddr*)&client_addr,&length);
    if( conn < 0) {
        LOG(ERROR)<<"accept";
        throw;
    }else{
        return wily::VAutoPtr<wily::VConnection>(new wily::VConnection(conn));
    }
}

/**
 * 链接函数，返回相应的链接VConnection
 * @return VConnection
 */
wily::VAutoPtr<wily::VConnection> wily::VSocket::connect() {
    int conn = ::connect(this->sockfd,(struct sockaddr*)&ser_addr, sizeof(this->ser_addr));
    if( conn < 0) {
        LOG(ERROR)<<"connect";
        throw;
    } else{
        return wily::VAutoPtr<wily::VConnection>(new wily::VConnection(this->sockfd));
    }
}

/**
 * 关闭链接，关闭当前存储的socketId
 */
void wily::VSocket::close() {
    ::close(this->sockfd);
}

/**
 *  析构函数
 */
wily::VSocket::~VSocket() = default;
