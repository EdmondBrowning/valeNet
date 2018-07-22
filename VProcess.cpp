//
// Created by edmond on 18-6-11.
//
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include "VProcess.h"

wily::VProcess::VProcess() = default;

void wily::VProcess::start() {
    if ((this->processId = (fork()) == 0)){
        this->run();
    }else {
        
    }
}

int wily::VProcess::getProcessId() {
    return this->processId;
}

void wily::VProcess::stop() {
    kill(this->processId, SIGKILL);
}
