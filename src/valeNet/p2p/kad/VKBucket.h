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
        std::list<VNode> kbucket;
    public:
        void* findVNode(std::string);
        void addVNode(VNode*);
    };
}


#endif //VALENET_VKBUCKET_H
