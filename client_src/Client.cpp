#include "Client.h"
#include "../common_src/ArgumentsException.h"
#include "../common_src/SocketException.h"
#include "../common_src/ProcoloException.h"
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

void Client::sendLine(char *buffer, int amountRead) {
    if (amountRead == 0) {
        return;
    }
    this->socket.send(buffer, amountRead);
}

void Client::run() {
    this->socket.connect(this->host, this->port);

    char buffer[64];

    do {
        int amountRead = fread(buffer, 1, 64, stdin);
        this->sendLine(buffer, amountRead);
    } while (!feof(stdin));

    this->socket.shutdownWrite();

    // wait receiving server response;

    this->socket.close();

    return;
}
