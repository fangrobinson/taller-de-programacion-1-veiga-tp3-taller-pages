#include <iostream>
#include <vector>
#include "ThAccept.h"
#include "ThClient.h"
#include "../common_src/Socket.h"

ThAccept::ThAccept(Socket *socket) {
    this->socket = socket;
}
ThAccept::~ThAccept() {}

void ThAccept::run() {
    std::cout << "THREAD ACCEPT" << std::endl;
    //std::vector<ThClient*> clientThreads;

    Socket peer;
    this->socket->accept(&peer);

    while (true) {
        break;
    }

    //ThClient *newThread = new ThClient(&peer);
    //clientThreads.push_back(newThread);
    return;
}