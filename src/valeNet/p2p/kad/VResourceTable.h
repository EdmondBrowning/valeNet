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
        std::map<std::string, VResource*> *resourceMap;
    public:
        VResource* findResource(std::string rid);
        void findResource(VResource* vResource);
    };
}


#endif //VALENET_VRESOURCETABLE_H
