//
// Created by edmond on 18-10-25.
//

#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include "../include/libwilydatagramsocket.h"

/**
 * VDatagramSocket构造器
 * @param address　地址
 * @param port　端口号
 */
wily::VDatagramSocket::VDatagramSocket(char address[], int port) {
    this->address = address;
    this->port = port;
    this->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(this->sockfd<0) {
//        fprintf(stderr,"socker Error:%s\n",strerror(errno));
        throw;
    }

    this->ser_addr.sin_family = AF_INET;
    this->ser_addr.sin_port = htons(static_cast<uint16_t>(this->port));
    this->ser_addr.sin_addr.s_addr = ::inet_addr(this->address);
}

wily::VDatagramSocket::VDatagramSocket(std::string address, int port) {
    char * addressData = const_cast<char *>(address.data());
    new (this)VDatagramSocket(addressData,port);
}


/**
 *　VDatagramSocket　绑定方法，将此socket调整为服务器模式
 */
void wily::VDatagramSocket::bind() {
    this->ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(::bind(this->sockfd, (struct sockaddr* ) &ser_addr, sizeof(ser_addr))<0) {
        perror("bind");
        throw;
    }
}

/**
 *　VDatagramSocket　发送信息
 * @param msg　所需要发送的信息
 */
void wily::VDatagramSocket::send(char * msg) {
    if(sendto(sockfd, msg, sizeof(msg), 0, (struct sockaddr*)&ser_addr, sizeof(struct sockaddr)) < 0){
            perror("sendto fail!\n");
    }
}

/**
 *　VDatagramSocket　发送信息
 * @param msg　所需要发送的信息
 */
void wily::VDatagramSocket::send(std::string msg) {
    char* msgData = const_cast<char *>(msg.data());
    send(msgData);
}

/**
 *　VDatagramSocket 监听方法,会产生阻塞,知道接收到信息
 * @return 返回所接收到的信息
 */
char *wily::VDatagramSocket::recv() {
    socklen_t sin_size = sizeof(client_addr);
    if(::recvfrom(sockfd, recvbuf, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &sin_size) < 0) {
        perror("recvfrom error!\n");
        throw;
    }
    return nullptr;
}

/**
 * VDatagramSocket 关闭通道操作，关闭自身所包含的 sockfd
 */
void wily::VDatagramSocket::close() {
    ::close(sockfd);
}

/**
 * VDatagramSocket 获取来源信息客户端信息
 * @return 返回结构体，包含来源客户端的信息
 */
struct sockaddr* wily::VDatagramSocket::getClientAddress() {
    return (struct sockaddr*)&(this->client_addr);
}

/**
 * VDatagramSocket 析构器
 */
wily::VDatagramSocket::~VDatagramSocket() = default;