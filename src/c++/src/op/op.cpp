//
// Created by edmond on 19-4-19.
//

#include <bitset>
#include "../resource/ResourceInfo.h"

namespace wily {

    enum OpType {
        FIND_VALUE, FIND_NODE, STORE, PING
    };

    struct op {
        OpType opType;
        std::bitset<160> key;
        ResourceInfo value;
    };
}