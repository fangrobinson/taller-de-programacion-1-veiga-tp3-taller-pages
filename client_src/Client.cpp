#include "Client.h"
#include <iostream>

Client::Client(int argc, char* argv[]) {
    if (argc != 3) {
        throw int(1);
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
}