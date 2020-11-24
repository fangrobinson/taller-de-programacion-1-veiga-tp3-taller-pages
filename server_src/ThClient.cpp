#include "ThClient.h"
#include "Thread.h"
#include <atomic>
#include <iostream>
#include <sstream>
#include "../common_src/SocketException.h"

ThClient::ThClient(Socket *peer, ResourceManager &resourceManager) : peer(peer), resourceManager(resourceManager) {
    //this->peer = peer;
    this->keepTalking = true;
    this->isRunning = true;
    this->start();
}

ThClient::~ThClient() {
    delete peer;
}

void ThClient::receiveInput(std::stringstream &input) {
    unsigned int size = 64;
    char buffer[64];
    int bytesRecibidos;
    do {
            bytesRecibidos = peer->receive(buffer, size);
            input.write(buffer, bytesRecibidos);
    } while (bytesRecibidos > 0);
}

void ThClient::clientRequestPrint(std::string &firstLine) {
    firstLine += "\n";
    std::cout << firstLine; // STDOUT SERVIDOR POR CONSULTA
}

void ThClient::run() {
    std::stringstream client_input, client_output, body;
    std::string firstLine, metodo, recurso, protocolo;
    while (this->keepTalking) {
        try {
            this->receiveInput(client_input);
        } catch (SocketException&) {
            this->keepTalking = false;
            break;
        }

        std::getline(client_input, firstLine, '\n');
        this->clientRequestPrint(firstLine);

        parser.parseFirstLine(firstLine, metodo, recurso, protocolo);
        //parser.skipHeader(client_input);
        //std::cout << metodo << recurso << protocolo;

        std::string response = "HTTP/1.1 200 OK\n\n";
        //"HTTP/1.1 403 FORBIDDEN\n\n"
        client_output << response;

        if (metodo == "GET") {
            std::string s = resourceManager.getResourceAt(recurso);;
            client_output << s;
        }

        if (metodo == "POST") {
            std::cout << "METODO POST" << std::endl;
        }

        peer->send(client_output.str().c_str(), client_output.str().size());

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
