//
// Created by edmond on 18-8-21.
//

#include "Object.h"

namespace wily{
    template<typename T>
    U_Ptr<T>::U_Ptr(T *ptr): p(ptr), count(1) {}
`
    template<typename T>
    U_Ptr<T>::~U_Ptr() { delete p; }
}