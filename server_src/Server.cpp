#include "Server.h"
#include <iostream>
#include "../common_src/Socket.h"
#include "ThAccept.h"

// hilo principal :
// -> lanza hilo aceptador
// c = cin.getc() while (c != q)
// socket close
// aceptador.join()

#define OK 0
#define ERROR 1

Server::Server() {}


void Server::run() {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "       SERVER RUNNING" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;


    this->serverSocket.bindAndListen("8080");

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