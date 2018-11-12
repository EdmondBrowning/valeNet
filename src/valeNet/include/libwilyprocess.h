//
// Created by edmond on 18-6-11.
//

#ifndef VALENET_VPROCESS_H
#define VALENET_VPROCESS_H
namespace wily{
    class VProcess{
    private:
        int processId;
        bool isRun;
        virtual void run();
    public:
        VProcess();
        void start();
        void stop();
        int getProcessId();
        ~VProcess();
    };
}
#endif //VALENET_VPROCESS_H
