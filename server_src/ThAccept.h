#ifndef SOLUTION_THACCEPT_H
#define SOLUTION_THACCEPT_H
#include "Thread.h"

class ThAccept : public Thread {
public:
    ThAccept();
    ~ThAccept();
    void run();
};


#endif //SOLUTION_THACCEPT_H
