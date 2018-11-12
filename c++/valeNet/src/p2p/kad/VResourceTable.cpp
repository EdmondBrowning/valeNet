//
// Created by edmond on 18-8-6.
//

#include "VResourceTable.h"

namespace wily{

    VResourceTable::VResourceTable() {
        this->resourceMap = new std::map<std::string,VResource*>();
    }

    void VResourceTable::addResource(VResource* vResource) {
        this->resourceMap->insert(std::pair<std::string, VResource*>(vResource->getRid().to_string(), vResource));
    }

    VResource* VResourceTable::findResource(std::bitset<160> rid) {
        auto iter = this->resourceMap->find(rid.to_string());
        if(iter != this->resourceMap->end())
            return iter->second;
        else
            return nullptr;
    }

    VResourceTable::~VResourceTable() {
        delete(this->resourceMap);
    }
}