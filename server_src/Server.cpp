#include "Server.h"
#include <iostream>
#include "../common_src/Socket.h"
#include "../common_src/ArgumentsException.h"
#include "ThAccept.h"

#define OK 0
#define ERROR 1

Server::Server(int argc, char* argv[]) {
    if (argc != 3) {
        throw ArgumentsException("");
    }
    this->port = argv[1];
    this->rootFile = argv[2];
}


void Server::run() {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "       SERVER RUNNING" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "PORT: " << this->port << std::endl;
    std::cout << "-----------------------------" << std::endl;

    this->serverSocket.bindAndListen(this->port);

    ThAccept thAccept(&this->serverSocket);

    thAccept.start();

    char c = std::cin.get();

    while (c != 'q') {
        c = std::cin.get();
    }

    this->serverSocket.close();

    thAccept.join();

    std::cout << "-----------------------------" << std::endl;
    std::cout << "       SERVER CLOSING" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;
}