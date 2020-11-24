#include <iostream>
#include <vector>
#include "ThAccept.h"
#include "ThClient.h"
#include "../common_src/Socket.h"
#include "../common_src/SocketException.h"

ThAccept::ThAccept(Socket &socket, ResourceManager &resourceManager) :
                                                                        socket(socket),
                                                                        resourceManager(resourceManager){}



ThAccept::~ThAccept() {
    this->murderSockets();
}

void ThAccept::reapDeadSockets() {
    unsigned int socketsAmount = this->clients.size();
    for (unsigned int i = 0; i < socketsAmount; i++) {
        if (this->clients[i]->isDead()) {
            this->clients[i]->stop();
            this->clients[i]->join();
            //this->clients.erase(this->clients.begin() + i);
            //delete this->clients[i];
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
    // MOVE SEMANTICS
    while (true) {
        Socket *peer;
        try {
            peer = this->socket.accept(); // pasarle
        } catch (SocketException&) {
            break;
        }

        this->clients.push_back(new ThClient(peer, this->resourceManager));
        //this->reapDeadSockets(); // una vez que se acepta un nuevo socket se limpian los thread zombie
    }
}

