#include "Client.h"
#include "../common_src/ArgumentsException.h"
#include "../common_src/SocketException.h"
#include <iostream>
#include <sstream>
#include <string>

Client::Client(int argc, char* argv[]) {
    if (argc != 3) {
        throw ArgumentsException("");
    }
    this->host = argv[1];
    this->port = argv[2];
}

Client::~Client() {
    this->socket.close();
}

void Client::sendLine(const char *buffer, int amountRead) {
    this->socket.send(buffer, amountRead);
}

void Client::run() {
    this->socket.connect(this->host, this->port);

    do {
        std::string lineRead;
        std::getline(std::cin, lineRead);
        if (lineRead.size() == 0) {
            lineRead = "";
        }
        lineRead += "\n";
        this->sendLine(lineRead.c_str(), lineRead.size());
    } while (!feof(stdin));

    this->socket.shutdownWrite();

    int bytesRecibidos;
    char buffer[64];
    do {
        bytesRecibidos = this->socket.receive(buffer, 64);
        std::string outBuffer(buffer, bytesRecibidos);
        std::cout << outBuffer;
    } while (bytesRecibidos > 0);
}
