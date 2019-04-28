//
// Created by edmond on 19-4-19.
//

#include "Resource.h"

void wily::Resource::setResourceId(std::bitset<160> mResourceId) {
    this->resourceId = mResourceId;
}

void wily::Resource::setResourceInfo(wily::ResourceInfo mResourceInfo) {
    this->resourceInfo = mResourceInfo;
}

wily::ResourceInfo wily::Resource::getResourceInfo() {
    return this->resourceInfo;
}

std::bitset<160> wily::Resource::getResourceId() {
    return this->resourceId;
}

