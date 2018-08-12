//
// Created by edmond on 18-8-10.
//

#ifndef VALENET_MAC_H
#define VALENET_MAC_H


#include <net/if.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <zconf.h>
#include <linux/if_ether.h>
#include <iomanip>

namespace wily{
    class Mac {
    private:
        std::string bytestohexstring(const char *bytes, int bytelength);
    public:
        std::string get_mac();
    };
}

#endif //VALENET_MAC_H
