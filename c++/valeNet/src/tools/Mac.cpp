//
// Created by edmond on 18-8-10.
//

#include "Mac.h"

namespace wily{
    std::string Mac::bytestohexstring(const char *bytes, int bytelength) {
        std::string str;
        std::string str2("0123456789abcdef");
        for (int i = 0; i < bytelength; i++) {
            int b;
            b = 0x0f & (bytes[i] >> 4);
            str.append(1, str2.at(static_cast<unsigned long>(b)));
            b = 0x0f & bytes[i];
            str.append(1, str2.at(static_cast<unsigned long>(b)));
        }
        return str;
    }

    std::string Mac::get_mac() {
        char *macaddr = new char[ETH_ALEN];
        char *device = const_cast<char *>("wlp7s0");
        struct ifreq req;
        std::string mac_address_str;
        int err, i;
        int s = socket(AF_INET, SOCK_DGRAM, 0);
        strcpy(req.ifr_name, device);
        err = ioctl(s, SIOCGIFHWADDR, &req);
        close(s);
        if (err != -1) {
            memcpy(macaddr, req.ifr_hwaddr.sa_data, ETH_ALEN); //取输出的MAC地址;
            mac_address_str = bytestohexstring(macaddr, ETH_ALEN);
        }
        return mac_address_str;
    }
}