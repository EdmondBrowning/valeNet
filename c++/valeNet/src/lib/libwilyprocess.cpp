//
// Created by edmond on 18-6-11.
//
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

#include "../include/libwilyprocess.h"

/**
 × VProcess构造器
 */
wily::VProcess::VProcess() {

}

/**
 * 多线程启动
 */
void wily::VProcess::start() {
    int pid_t;
    pid_t = fork();
    if ( pid_t == 0){
        this->run();
    }
}

/**
 * 获取线程id
 * @return processId
 */
int wily::VProcess::getProcessId() {
    return this->processId;
}

/**
 * 停止线程
 */
void wily::VProcess::stop() {
    std::cout<<this->getProcessId()<<std::endl;
    kill(this->processId, SIGKILL);
}

/**
 * 线程执行函数
 */
void wily::VProcess::run() {

}


/**
 * VProcess析构器
 */
wily::VProcess::~VProcess() {

}

