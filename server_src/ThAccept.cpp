#include <iostream>
#include <vector>
#include "ThAccept.h"
#include "ThClient.h"
#include "../common_src/Socket.h"
#include "../common_src/SocketException.h"

ThAccept::ThAccept(Socket *socket) {
    this->socket = socket;
}
ThAccept::~ThAccept() {}

void ThAccept::reapDeadSockets() {
    unsigned int socketsAmount = this->clients.size();
    for (unsigned int i = 0; i < socketsAmount; i++) {
        if (this->clients[i]->isDead()) {
            this->clients[i]->stop();
            this->clients[i]->join();
            delete this->clients[i];
        }
    }
}

void ThAccept::murderSockets() {
    unsigned int socketsAmount = this->clients.size();
    for (unsigned int i = 0; i < socketsAmount; i++) {
        this->clients[i]->stop();
        this->clients[i]->join();
        delete this->clients[i];
    }
}

void ThAccept::run() {
    while (true) {
        Socket peer;
        try {
            this->socket->accept(&peer);
        } catch (SocketException&) {
            break;
        }

        this->clients.push_back(new ThClient(&peer));
        this->reapDeadSockets();
    }

    this->murderSockets();

    return;
}