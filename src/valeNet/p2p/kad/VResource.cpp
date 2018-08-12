#include <utility>

#include <utility>

//
// Created by edmond on 18-8-6.
//

#include "VResource.h"

namespace wily{

    VResource::VResource() {

    }

    void VResource::setAddress(std::string address) {
        this->address = std::move(address);
    }

    void VResource::setPort(int port) {
        this->port = port;
    }

    void VResource::setUrl(std::string url) {
        this->url = std::move(url);
    }

    std::bitset<160> VResource::getRid() {
        return this->rid;
    }

    std::string VResource::getAddress() {
        return this->address;
    }

    int VResource::getPort() {
        return this->port;
    }

    std::string VResource::getUrl() {
        return this->url;
    }

    VResource::~VResource() {

    }

    void VResource::setRid(std::bitset<160> rid) {
        this->rid = rid;
    }

    std::string VResource::getProtocol() {
        return protocol;
    }

    void VResource::setProtocol(std::string protocol) {
        this->protocol = protocol;
    }
}
