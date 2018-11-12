//
// Created by edmond on 18-8-6.
//

#ifndef VALENET_VRESOURCETABLE_H
#define VALENET_VRESOURCETABLE_H

#include <map>
#include "VResource.h"

namespace wily{
    class VResourceTable {
    private:
        std::map<std::string, VResource*>* resourceMap = nullptr;
    public:
        VResourceTable();
        VResource* findResource(std::bitset<160> rid);
        void addResource(VResource* vResource);
        ~VResourceTable();
    };
}


#endif //VALENET_VRESOURCETABLE_H
