//
// Created by edmond on 18-8-6.
//

#include "VKBucket.h"

namespace wily{

    VKBucket::VKBucket() {
        this->kbucket = new std::list<VNode>();
    }

    void *VKBucket::findVNode(std::string) {
        return nullptr;
    }

    void VKBucket::addVNode(VNode *) {

    }

    VKBucket::~VKBucket() {
        delete(this->kbucket);
    }
}