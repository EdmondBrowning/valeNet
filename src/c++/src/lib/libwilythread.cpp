//
// Created by edmond on 18-9-25.
//

#include <pthread.h>
#include <iostream>
#include "../include/libwilythread.h"

/**
 * VThread默认构造器,默认执行空白函数
 */
wily::VThread::VThread() {
    new(this)VThread(this->__start_routine, true);
}

/**
 * VThread构造器，传入线程执行的函数(需静态函数)
 * @param __start_routine
 */
wily::VThread::VThread(void *(*__start_routine)(void *)) {
    new(this)VThread(__start_routine, true);
}

/**
 * VThread构造器，传入线程执行的函数(需静态函数)，是否加入
 * @param __start_routine
 * @param isJoin
 */
wily::VThread::VThread(void *(*__start_routine)(void *), bool isJoin) {
    this->__start_routine = __start_routine;
    pthread_attr_init(&(this->attr));
    if (isJoin){
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    }else{
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    }
}

/**
 * 线程开始执行
 */
void wily::VThread::start() {
    pthread_create(&(this->pid),&(this->attr),this->__start_routine, nullptr);
    pthread_attr_destroy(&(this->attr));
}

/**
 * 线程停止执行
 */
void wily::VThread::stop() {
    pthread_attr_destroy(&(this->attr));
}

/**
 * VThread析构
 */
wily::VThread::~VThread() = default;

