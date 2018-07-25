//
// Created by edmond on 18-6-11.
//
#include <zconf.h>
#include <iostream>
#include <sys/wait.h>
#include "VProcess.h"

wily::VProcess::VProcess() = default;

void wily::VProcess::start() {
    int pid_t;
    pid_t = fork();
    if ( pid_t == 0){
        this->run();
    }else {
        std::cout<<pid_t<<std::endl;
        this->processId = pid_t;
    }
}

int wily::VProcess::getProcessId() {
    return this->processId;
}

void wily::VProcess::stop() {
    std::cout<<this->getProcessId()<<std::endl;
    kill(this->processId, SIGKILL);
}
