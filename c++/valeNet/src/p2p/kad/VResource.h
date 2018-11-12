//
// Created by edmond on 18-8-6.
//

#ifndef VALENET_VRESOURCE_H
#define VALENET_VRESOURCE_H

#include <string>
#include <bitset>

namespace wily{
    class VResource {
    private:
        std::bitset<160> rid;
        std::string address;
        int port;
        std::string url;
        std::string protocol;
        void setRid(std::bitset<160> rid);
        void setAddress(std::string address);
        void setPort(int port);
        void setProtocol(std::string);
        void setUrl(std::string url);
    public:
        VResource();
        std::bitset<160> getRid();
        std::string getAddress();
        int getPort();
        std::string getProtocol();
        std::string getUrl();
        ~VResource();
    };
}


#endif //VALENET_VRESOURCE_H
