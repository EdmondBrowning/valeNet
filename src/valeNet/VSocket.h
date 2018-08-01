//
// Created by edmond on 18-6-7.
//

#ifndef VALENET_VSOCKET_H
#define VALENET_VSOCKET_H

namespace wily{
    class VSocket{
    public:
        VSocket();
        ~VSocket();
    private:
        bool isflag;
        void create();
    };
}
#endif //VALENET_VSOCKET_H
