#include "Server.h"
#include <iostream>
#include "../common_src/Socket.h"
#include "../common_src/ArgumentsException.h"
#include "ThAccept.h"
#include <string>

Server::Server(int argc, char* argv[]) {
    if (argc != 3) {
        throw ArgumentsException("");
    }
    this->port = argv[1];
    this->rootFile = argv[2];
    this->serverSocket.bindAndListen(this->port);
}

Server::~Server() {}

void Server::run() {
    ThAccept thAccept(this->serverSocket, std::string(this->rootFile));
    thAccept.start();

    char c = std::cin.get();
    while (c != 'q') {
        c = std::cin.get();
    }
    this->serverSocket.close();
    thAccept.join();
}
