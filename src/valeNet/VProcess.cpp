//
// Created by edmond on 18-6-11.
//
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include "VProcess.h"

namespace wily{

    VProcess::VProcess() = default;

    void VProcess::start() {
        int pid_t;
        pid_t = fork();
        if ( pid_t == 0){
            this->run();
        }else {
            std::cout<<pid_t<<std::endl;
            this->processId = pid_t;
        }
    }

    int VProcess::getProcessId() {
        return this->processId;
    }

    void VProcess::stop() {
        std::cout<<this->getProcessId()<<std::endl;
        kill(this->processId, SIGKILL);
    }

    void VProcess::run(){}
}