//
// Created by edmond on 18-8-6.
//

#ifndef VALENET_VKAD_H
#define VALENET_VKAD_H

#include <array>
#include "VNode.h"
#include "VResource.h"
#include "VKBucket.h"
#include "VResourceTable.h"

namespace wily{
    class VKad{
    private:
        std::array<VKBucket* ,160>* bucketList = nullptr;
        VNode* selfNode;
        VResourceTable* vResourceTable;
        VKad();
        VKad(const VKad &);
        VKad & operator = (const VKad &);
        ~VKad();
    public:
        static VKad* getInstance();
        void* findNearLestNode(VResource*);
        void* findNearLestNode(std::bitset<160>);
        void addNode(VNode*);
        VResource* findResource(std::bitset<160> rid);
        VResource* findResource(VResource* vResource);
    };
}
#endif //VALENET_VKAD_H
