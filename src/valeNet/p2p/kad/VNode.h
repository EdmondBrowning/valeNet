//
// Created by edmond on 18-8-6.
//

#ifndef VALENET_VNODE_H
#define VALENET_VNODE_H


#include <string>
#include <bitset>

namespace wily{
    class VNode{
    private:
        std::bitset<160> nid;
        std::string address;
        void setNid(std::bitset<160> nid);
        void setAddress(std::string address);
    public:
        VNode();
        VNode(std::string);
        VNode(std::string,std::bitset<160>);
        std::bitset<160> getNid();
        std::string getAddress();
        ~VNode();
    };
}


#endif //VALENET_VNODE_H
