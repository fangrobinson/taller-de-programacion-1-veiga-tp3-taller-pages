#include "Client.h"
#include "../common_src/ArgumentsException.h"
#include <iostream>
#include <sstream>

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



    std::string firstLine;

    std::getline(std::cin, firstLine);

    std::stringstream ss(firstLine);

    std::string method;

    std::string resource;

    std::string protocol;

    ss >> method;
    ss >> resource;
    ss >> protocol;

    std::cout << "Metodo: " << method << std::endl;
    std::cout <<  "Resource: " << resource << std::endl;
    std::cout <<  "Protocolo: " << protocol << std::endl;

    while (std::getline(std::cin, firstLine) && !firstLine.empty()) {
        std::cout << "Linea: " << firstLine << std::endl;
    }
}