#include "Server.h"
#include <iostream>
#include "../common_src/Socket.h"

// hilo principal :
// -> lanza hilo aceptador
// c = cin.getc() while (c != q)
// socket close
// aceptador.join()

#define OK 0
#define ERROR 1

Server::Server() {}


int Server::run() {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "       SERVER RUNNING" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;

    char c = std::cin.get();

    while (c != 'q') {
        c = std::cin.get();
    }

    std::cout << "-----------------------------" << std::endl;
    std::cout << "       SERVER CLOSING" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;

    return 0;
    Socket serverSocket;
    /*
    // hardcoded port
    int binded = serverSocket.socket_bindAndListen("8080");

    if (binded != OK) {
        return ERROR;
    }

    Socket socketToAccept;

    socketToAccept.

    int accepted = serverSocket.socket_accept(&socketToAccept);
    if (accepted != OK) {
        return ERROR;
    }
    */
    /*
    char *buffer = malloc(server->buffer_size);
    int bytes_recibidos;

    do {
        bytes_recibidos = socket_receive(&socket_to_accept,
                                         buffer, server->buffer_size);
        controlador_cifradores_descifrar(&server->cifradores, buffer,
                                         bytes_recibidos);
        fwrite(buffer, 1, bytes_recibidos, stdout);
    } while (bytes_recibidos == server->buffer_size);

    socket_shutdown(&socket_to_accept);
    socket_uninit(&socket_to_accept);
    free(buffer);
     */
    return OK;
}