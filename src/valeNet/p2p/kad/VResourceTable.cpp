//
// Created by edmond on 18-8-6.
//

#include "VResourceTable.h"

namespace wily{
    VResource *VResourceTable::findResource(std::string rid) {
        return nullptr;
    }

    void VResourceTable::findResource(VResource *vResource) {

    }

    VResourceTable::VResourceTable() {
        this->resourceMap = new std::map<std::string,VResource*>()
    }

    VResourceTable::~VResourceTable() {
        delete(this->resourceMap);
    }
}