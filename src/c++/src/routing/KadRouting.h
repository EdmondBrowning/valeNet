//
// Created by edmond on 19-4-28.
//

#ifndef VALENET_KADROUTING_H
#define VALENET_KADROUTING_H

#include "Bucket.h"

#define BUCKET_NUM 160

namespace wily{
    class KadRouting {
    private:
        Bucket* bucketList[BUCKET_NUM];
    public:
        void init();
        Bucket** getBucketList();
    };
}


#endif //VALENET_KADROUTING_H
