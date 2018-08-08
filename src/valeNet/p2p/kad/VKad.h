//
// Created by edmond on 18-8-6.
//

#ifndef VALENET_VKAD_H
#define VALENET_VKAD_H

#include <array>
#include "VNode.h"
#include "VResource.h"

namespace wily{

    class VKBucket;
    class VKad{
    private:
        std::array<VKBucket ,160>* bucketList;
    public:
        VKad();
        VNode* findNearLestNode(VResource);
        void addNode(VNode*);
        ~VKad();
};
}
#endif //VALENET_VKAD_H
