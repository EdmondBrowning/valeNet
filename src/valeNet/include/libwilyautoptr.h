#ifndef VALE_LIBRARY_H
#define VALE_LIBRARY_H

#include <iostream>
#include "libwilyloger.h"

namespace wily{
    template<typename T>
    class VAutoPtr;
    template<typename T>
    class U_Ptr {
    private:
        friend class VAutoPtr<T>;
        int count{};
        T* p;
        explicit U_Ptr(T* ptr);
        ~U_Ptr();
    };
    template<typename T>
    class VAutoPtr {
    private:
        U_Ptr<T>* rp;
        pthread_mutex_t mutex;
    public:
        VAutoPtr();
        explicit VAutoPtr(T* ptr);//构造函数
        VAutoPtr(const VAutoPtr<T>& sp); //复制构造函数
        VAutoPtr<T> &operator=(const VAutoPtr<T>& rhs);
        T &operator*();//重载*操作符
        T *operator->();//重载->操作符
        ~VAutoPtr();
    };

    /**
     *
     * @tparam T
     */
    template<typename T>
    VAutoPtr<T>::VAutoPtr() {
        this(new T());
    }

    /**
     *
     * @tparam T
     * @param ptr
     */
    template<typename T>
    VAutoPtr<T>::VAutoPtr(T* ptr):rp(new U_Ptr<T>(ptr)) {}

    /**
     *
     * @tparam T
     * @param sp
     */
    template<typename T>
    VAutoPtr<T>::VAutoPtr(const VAutoPtr<T>& sp):rp(sp.rp) {
        pthread_mutex_lock(&mutex);
        ++rp->count;
        pthread_mutex_unlock(&mutex);
    }

    /**
     *
     * @tparam T
     * @param rhs
     * @return
     */
    template<typename T>
    VAutoPtr<T>& VAutoPtr<T>::operator=(const VAutoPtr<T>& rhs) {
        pthread_mutex_lock(&mutex);
        ++rhs.rp->count;     //首先将右操作数引用计数加1，
        --rp->count;
        pthread_mutex_unlock(&mutex);
        if (rp->count == 0)     //然后将引用计数减1，可以应对自赋值
            delete rp;
        rp = rhs.rp;
        return *this;
    }

    /**
     *
     * @tparam T
     * @return
     */
    template<typename T>
    T& VAutoPtr<T>::operator*() {
        return *(rp->p);
    }

    /**
     *
     * @tparam T
     * @return
     */
    template<typename T>
    T* VAutoPtr<T>::operator->() {
        return rp->p;
    }

    /**
     *
     * @tparam T
     */
    template<typename T>
    VAutoPtr<T>::~VAutoPtr() {        //析构函数
        pthread_mutex_lock(&mutex);
        --rp->count;
        pthread_mutex_unlock(&mutex);
        if (rp->count == 0) {
            LOG(INFO)<<"the memory will be delete";
            delete rp;
        } else if (rp->count < 0) {
            LOG(ERROR)<<"the number of pointer is less than 0";
        } else {
            LOG(INFO)<<"the point release "<<rp->count << std::endl;
        }
    }

    /**
     *
     * @tparam T
     * @param ptr
     */
    template<typename T>
    U_Ptr<T>::U_Ptr(T *ptr):p(ptr), count(1) {}

    /**
     *
     * @tparam T
     */
    template<typename T>
    U_Ptr<T>::~U_Ptr() {
        delete p;
    }
}

#endif