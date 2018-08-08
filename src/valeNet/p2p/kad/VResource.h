//
// Created by edmond on 18-8-6.
//

#ifndef VALENET_VRESOURCE_H
#define VALENET_VRESOURCE_H

#include <string>

namespace wily{
    class VResource {
    private:
        std::string rid;
        std::string address;
        int port;
        std::string url;
        void setRid(std::string rid);
        void setAddress(std::string address);
        void setPort(int port);
        void setUrl(std::string url);
    public:
        VResource();
        std::string getRid();
        std::string getAddress();
        int getPort();
        std::string getUrl();
        ~VResource();
    };
}


#endif //VALENET_VRESOURCE_H
