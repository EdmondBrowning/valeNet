//
// Created by edmond on 19-4-19.
//

#ifndef VALENET_RESOURCE_H
#define VALENET_RESOURCE_H


#include <bitset>
#include "ResourceInfo.h"

namespace wily {
    class Resource {
        std::bitset<160> resourceId;
        ResourceInfo resourceInfo;
    public:
        void setResourceId(std::bitset<160>);
        void setResourceInfo(ResourceInfo);
        std::bitset<160> getResourceId();
        ResourceInfo getResourceInfo();
    };
}


#endif //VALENET_RESOURCE_H
