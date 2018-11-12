//
// Created by edmond on 18-8-6.
//

#ifndef VALENET_VKBUCKET_H
#define VALENET_VKBUCKET_H

#include <list>
#include "VNode.h"

namespace wily{
    class VKBucket {
    private:
        std::list<VNode>* kbucket = nullptr;
        bool isAlive(VNode*);
    public:
        VKBucket();
        void* findVNode(std::bitset<160>);
        void addVNode(VNode*);
        ~VKBucket();
    };
}


#endif //VALENET_VKBUCKET_H
