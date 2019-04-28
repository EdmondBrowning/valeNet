//
// Created by edmond on 18-6-11.
//
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <sstream>

#include "../include/libwilyprocess.h"
#include "../include/libwilyloger.h"

/**
 * VProcess构造器
 */
wily::VProcess::VProcess() = default;

/**
 * 多进程程启动
 */
void wily::VProcess::start() {
    int pid_t;
    pid_t = fork();
    if ( pid_t == 0){
        this->run();
    }else {
        this->processId = pid_t;
    }
}

/**
 * 获取进程id
 * @return processId
 */
int wily::VProcess::getProcessId() {
    return this->processId;
}

/**
 * 停止进程
 */
void wily::VProcess::stop() {
    std::stringstream ss;
    ss<<this->getProcessId();
    std::string processIdStr;
    ss>>processIdStr;
    LOG(INFO)<<"the process "+processIdStr+"will be killing"<<std::endl;
    kill(this->processId, SIGKILL);
}

/**
 * 进程执行函数
 */
void wily::VProcess::run() {

}


/**
 * VProcess析构器
 */
wily::VProcess::~VProcess() = default;

