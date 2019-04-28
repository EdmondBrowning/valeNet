//
// Created by edmond on 19-4-28.
//

#ifndef VALENET_BUCKET_H
#define VALENET_BUCKET_H


#include <vector>
#include "Node.h"

namespace wily{
    class Bucket {
    private:
        std::vector<Node>* nodeList = new std::vector<Node>();
    public:
        std::vector<Node>* getNodeList();
    };
}


#endif //VALENET_BUCKET_H
