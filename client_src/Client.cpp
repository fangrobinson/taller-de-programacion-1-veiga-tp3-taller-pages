#include "Client.h"
#include "../common_src/ArgumentsException.h"
#include <iostream>

Client::Client(int argc, char* argv[]) {
    if (argc != 3) {
        throw ArgumentsException("");
    }
    this->host = argv[1];
    this->port = argv[2];
}
Client::~Client() {}

void Client::run() {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "       CLIENT RUNNING" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << this->host << std::endl;
    std::cout << this->port << std::endl;

    this->socket.connect(this->host, this->port);
    std::cout << "CONNECTED" << std::endl;
}