#include <iostream>
#include <vector>
#include "ThAccept.h"
#include "ThClient.h"
#include "../common_src/Socket.h"
#include "../common_src/SocketException.h"
#include <string>

ThAccept::ThAccept(Socket &socket, std::string rootFileName) :
                   socket(socket),
                   resourceManager(rootFileName){}

ThAccept::~ThAccept() {
    this->murderSockets();
}

void ThAccept::reapDeadSockets() {
    auto it = this->clients.begin();

    while (it != this->clients.end()) {
        if ((*it)->isDead()) {
            (*it)->join();
            delete (*it);
            it = this->clients.erase(it);
        }
    }
}

void ThAccept::murderSockets() {
    auto it = this->clients.begin();
    while (it != this->clients.end()) {
        (*it)->stop();
        (*it)->join();
        delete (*it);
        it = this->clients.erase(it);
    }
}

void ThAccept::run() {
    while (true) {
        Socket *peer;
        try {
            peer = this->socket.accept();
        } catch(SocketException&) {
            break;
        }

        this->clients.push_back(new ThClient(peer, this->resourceManager));

        this->reapDeadSockets();
    }
}

