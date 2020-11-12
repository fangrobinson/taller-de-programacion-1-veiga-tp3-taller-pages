#ifndef SOLUTION_THACCEPT_H
#define SOLUTION_THACCEPT_H
#include "Thread.h"
#include "../common_src/Socket.h"

class ThAccept : public Thread {
public:
    ThAccept(Socket *socket);
    ~ThAccept();
    void run();

private:
    Socket *socket;
};


#endif //SOLUTION_THACCEPT_H
