#ifndef SOLUTION_THACCEPT_H
#define SOLUTION_THACCEPT_H
#include "Thread.h"
#include "../common_src/Socket.h"
#include <vector>
#include "ThClient.h"
#include "ResourceManager.h"

class ThAccept : public Thread {
public:
    ThAccept(Socket &socket, ResourceManager &resourceManager);
    ~ThAccept() override;
    void run() override;

private:
    Socket &socket;
    std::vector<ThClient*> clients;
    ResourceManager &resourceManager;
    void reapDeadSockets();
    void murderSockets();
};


#endif //SOLUTION_THACCEPT_H
