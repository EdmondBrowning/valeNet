//
// Created by edmond on 18-6-11.
//

#ifndef VALENET_VPROCESS_H
#define VALENET_VPROCESS_H
namespace wily{
    class VProcess{
    private:
        int processId = 0;
        bool isRun = false;
        virtual void run()= 0;
    public:
        VProcess();
        void start();
        void stop();
        int getProcessId();
    };
}
#endif //VALENET_VPROCESS_H
