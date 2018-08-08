//
// Created by edmond on 18-8-6.
//

#include "VKBucket.h"

namespace wily{

    void *VKBucket::findVNode(std::string) {
        return nullptr;
    }

    void VKBucket::addVNode(VNode *) {

    }

    VKBucket::VKBucket() {
        this->kbucket = new std::list<VNode>();
    }

    VKBucket::~VKBucket() {
        delete(this->kbucket);
    }
}