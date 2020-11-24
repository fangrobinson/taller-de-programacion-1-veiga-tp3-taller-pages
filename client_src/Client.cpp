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

Client::~Client() {
    this->socket.close();
}

void Client::sendLine(const char *buffer, int amountRead) {
    this->socket.send(buffer, amountRead);
}

void Client::run() {
    this->socket.connect(this->host, this->port);

    do {
        //printf("CLIENT RUN - READING");
        std::string lineRead;
        std::getline(std::cin, lineRead);
        if (lineRead.size() == 0) {
            continue;
        }
        this->sendLine(lineRead.c_str(), lineRead.size());
        //int amountRead = fread(buffer, 1, 64, stdin);
        //printf("Amount read: %d", amountRead);
        //this->sendLine(buffer, amountRead);
    } while (!feof(stdin));

    this->socket.shutdownWrite();

    // wait receiving server response;
}
