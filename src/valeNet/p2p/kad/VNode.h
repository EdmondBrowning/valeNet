//
// Created by edmond on 18-8-6.
//

#ifndef VALENET_VNODE_H
#define VALENET_VNODE_H


#include <string>

namespace wily{
    class VNode{
    private:
        std::string nid;
        std::string address;
        void setNid(std::string nid);
        void setAddress(std::string address);
    public:
        std::string getNid();
        std::string getAddress();
    };
}


#endif //VALENET_VNODE_H
