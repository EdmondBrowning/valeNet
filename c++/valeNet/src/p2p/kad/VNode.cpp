#include <utility>

#include <utility>

//
// Created by edmond on 18-8-6.
//

#include "VNode.h"

namespace wily{

    VNode::VNode() {

    }

    VNode::VNode(std::string address) {
        this->setAddress(std::move(address));
    }

    VNode::VNode(std::string address, std::bitset<160> nid) {
        this->setAddress(std::move(address));
        this->setNid(nid);
    }

    void VNode::setAddress(std::string address) {
        this->address = std::move(address);
    }

    std::string VNode::getAddress() {
        return this->address;
    }

    VNode::~VNode() {

    }

    std::bitset<160> VNode::getNid() {
        return this->nid;
    }

    void VNode::setNid(std::bitset<160> nid) {

    }
}
