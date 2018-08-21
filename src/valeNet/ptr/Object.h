//
// Created by edmond on 18-8-21.
//

#ifndef VALENET_OBJECT_H
#define VALENET_OBJECT_H

namespace wily {

    template<typename T>
    class Object;

    template<typename T>
    class U_Ptr {
    private:
        friend class Object<T>;
        U_Ptr(T *ptr);
        ~U_Ptr();
        int count;
        T *p;
    };

    template<typename T>

    class Object {
    private:
        U_Ptr<T> *rp;
    public:
        Object(T *ptr) : rp(new U_Ptr<T>(ptr)) {}

        Object(const Object<T> &sp) : rp(sp.rp) { ++rp->count; }

        Object &operator=(const Object<T> &rhs) {
            ++rhs.rp->count;
            if (--rp->count == 0) {
                delete rp;
            }
            rp = rhs.rp;
            return *this;
        }

        T &operator*() {
            return *(rp->p);
        }

        T *operator->() {
            return rp->p;
        }

        ~Object() {
            if (--rp->count == 0)
                delete rp;
        }
    };
}


#endif //VALENET_OBJECT_H
