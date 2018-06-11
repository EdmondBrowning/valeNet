//
// Created by edmond on 18-6-7.
//
#include <iostream>
#include "VSocket.h"

using namespace std;

wily::VSocket::VSocket() {
    create();
}

void wily::VSocket::create() {
    cout<<"create VSocket"<<endl;
}

wily::VSocket::~VSocket() = default;

