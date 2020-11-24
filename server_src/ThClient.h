#ifndef SOLUTION_THCLIENT_H
#define SOLUTION_THCLIENT_H

#include <atomic>
#include "Thread.h"
#include "../common_src/Socket.h"
#include "LineParser.h"
#include "ResourceManager.h"
#include <string>

class ThClient : public Thread {
private:
    Socket *peer;
    ResourceManager &resourceManager;
    std::atomic<bool> keepTalking;
    std::atomic<bool> isRunning;
    LineParser parser;
    void receiveInput(std::stringstream &input);
    void clientRequestPrint(std::string &firstLine);
public:
    ThClient(Socket *peer, ResourceManager &resourceManager);
    ~ThClient() override;
    void run() override;
    void stop();
    bool isDead();
};


#endif //SOLUTION_THCLIENT_H
