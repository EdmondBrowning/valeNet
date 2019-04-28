//
// Created by edmond on 19-4-28.
//

#include "KadRouting.h"

void wily::KadRouting::init() {
    for (auto &loop : this->bucketList) {
        loop = new Bucket();
    }
}

wily::Bucket** wily::KadRouting::getBucketList() {
    return this->bucketList;
}
