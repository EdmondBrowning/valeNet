//
// Created by edmond on 18-8-6.
//

#include "VKad.h"

namespace wily {

    VKad::VKad(){
        this->bucketList = new std::array<VKBucket ,160>();
    }

    VNode* VKad::findNearLestNode(VResource vResource) {
        return new VNode();
    }

    void VKad::addNode(VNode* vNode) {

    }

    VKad::~VKad(){
        delete(this->bucketList);
    }
}