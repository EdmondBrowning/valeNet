//
// Created by edmond on 19-2-2.
//

#ifndef VALE_LIBWILYPOOL_H
#define VALE_LIBWILYPOOL_H

#include <queue>
#include "libwilyautoptr.h"

namespace wily {
    template <typename T>
    class VPool {
    private:
        VPool();
        VPool<T>(const VPool<T>&);
        VPool<T>& operator = (const VPool<T>&);
        static VPool<T>* instance;

        std::queue<T*>* resourcePool;
    public:
        static pthread_mutex_t mtx;
        static VPool<T>* getInstance();
        T* getT();
        void addT(VAutoPtr<T>);
        void destory();
    };

    template <typename T>
    VPool<T>* VPool<T>::getInstance() {
        if(nullptr == instance){
            pthread_mutex_lock(&mtx);
            instance = new VPool<T>();
            pthread_mutex_unlock(&mtx);
        }
        return instance;
    }

    template <typename T>
    VPool<T>::VPool() {
        this->resourcePool = new std::queue<T*>();
    }

    template<typename T>
    T* VPool<T>::getT() {
        if (this->resourcePool->empty()){
            return new T();
        }else {
            T* resource = this->resourcePool->front();
            this->resourcePool->pop();
            return resource;
        }
    }

    template<typename T>
    void VPool<T>::addT(VAutoPtr <T>) {

    }

    template<typename T>
    void VPool<T>::destory() {

    }

    template <typename T>
    pthread_mutex_t VPool<T>::mtx;
    template <typename T>
    VPool<T>* VPool<T>::instance= NULL;
}

#endif //VALE_LIBWILYPOOL_H
