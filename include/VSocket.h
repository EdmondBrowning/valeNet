//
// Created by edmond on 18-6-7.
//

#ifndef VALENET_VSOCKET_H
#define VALENET_VSOCKET_H

namespace wily{
    class VSocket{
    public:
        VSocket();
        void create();
        ~VSocket();
    private:
        bool isflag;
    };
}
#endif //VALENET_VSOCKET_H
