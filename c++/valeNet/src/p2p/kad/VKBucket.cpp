//
// Created by edmond on 18-8-6.
//

#include <iostream>
#include "VKBucket.h"

namespace wily{

    VKBucket::VKBucket() {
        this->kbucket = new std::list<VNode>();
    }

    void VKBucket::addVNode(VNode *) {

    }

    VKBucket::~VKBucket() {
        delete(this->kbucket);
    }

    void *VKBucket::findVNode(std::bitset<160>) {
        std::cout<<"sdfds"<<std::endl;
        return nullptr;
    }

    bool VKBucket::isAlive(VNode *) {
        return false;
    }
}