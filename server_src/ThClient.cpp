#include "ThClient.h"
#include "Thread.h"
#include <atomic>
#include <iostream>
#include <sstream>
#include "../common_src/SocketException.h"

ThClient::ThClient(Socket *peer) {
    this->peer = peer;
    this->keepTalking = true;
    this->isRunning = true;
    this->start();
}

ThClient::~ThClient() {
    delete peer;
}

void ThClient::run() {
    unsigned int size = 64;
    char buffer[64];
    int bytesRecibidos;
    std::stringstream ss;
    while (this->keepTalking) {
        try {
            do {
                bytesRecibidos = peer->receive(buffer, size);
                ss.write(buffer, bytesRecibidos);
            } while (bytesRecibidos > 0);
        } catch (SocketException&) {
            this->keepTalking = false;
            break;
        }

        std::cout << "ThClient Received: " << ss.str() << std::endl;

        std::string response = "Recibido perri";
        peer->send(response.c_str(), response.size());

        this->keepTalking = false;
        // ThClient should process received,
        // call properly Request with polymorphism
        // send response to client
    }
    this->isRunning = false;
}

void ThClient::stop() {
    peer->close();
    keepTalking = false;
    this->isRunning = false;
}

bool ThClient::isDead() {
    return not this->isRunning;
}
