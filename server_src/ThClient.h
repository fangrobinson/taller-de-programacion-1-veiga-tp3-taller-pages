/*
#ifndef SOLUTION_THCLIENT_H
#define SOLUTION_THCLIENT_H

#include <atomic>
#include "Thread.h"
#include "../common_src/Socket.h"

class ThClient : public Thread {
private:
    Socket peer;
    std::atomic<bool> keepTalking;
    std::atomic<bool> isRunning;
public:
    ThClient();
    ~ThClient();
    void run();
    void stop();
};


#endif //SOLUTION_THCLIENT_H
*/