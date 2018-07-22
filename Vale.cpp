//
// Created by edmond on 18-6-7.
//

#include <iostream>
#include <unistd.h>
#include "VSocket.h"
#include "VProcess.h"

using namespace std;

class MyProcess:public wily::VProcess{
private:
    void run() override {
        cout<<"the child process is working"<<endl;
        sleep(1000);
        cout<<"the child process is end"<<endl;
    }

public:
    MyProcess();
};

MyProcess::MyProcess() = default;


int main(){
    auto * vProcess = new MyProcess();
    vProcess->start();
}
