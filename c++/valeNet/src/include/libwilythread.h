//
// Created by edmond on 18-9-25.
//

#ifndef VTHREAD_VTHREAD_H
#define VTHREAD_VTHREAD_H


#include <sys/types.h>

namespace wily {
    class VThread {
    private:
        pthread_t pid;
        pthread_attr_t attr;
        void *(*__start_routine)(void *);
    public:
        VThread();
        explicit VThread(void *(*__start_routine)(void *));
        explicit VThread(void *(*__start_routine)(void *), bool isJoin);
        void start();
        void stop();
        ~VThread();
    };
}


#endif //VTHREAD_VTHREAD_H
