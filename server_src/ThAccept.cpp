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
    printf("REAPer came: %d\n", socketsAmount);
    for (unsigned int i = 0; i < socketsAmount; i++) {
        if (this->clients[i]->isDead()) {
            printf("REAPING AHSHAFAS\n");
            this->clients[i]->stop();
            this->clients[i]->join();
            printf("JOINED\n");
            delete this->clients[i];
        }
    }
}

void ThAccept::run() {
    std::cout << "THREAD ACCEPT" << std::endl;

    while (true) {
        Socket peer;
        try {
            this->socket->accept(&peer);
        } catch (SocketException) {
            //std::cout << "Socket closed from other thread." << std::endl;
            break;
        }

        //this->clients.reserve(1);
        this->clients.push_back(new ThClient(&peer));
        //std::cout << "DISCOVERED!" << std::endl;
        //std::cout << clients.size() << std::endl;
        this->reapDeadSockets();
    }


    return;
}