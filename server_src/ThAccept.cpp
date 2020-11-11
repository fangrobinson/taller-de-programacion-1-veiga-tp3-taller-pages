#include <iostream>
#include <vector>
#include "ThAccept.h"
#include "../common_src/Socket.h"

ThAccept::ThAccept() {}
ThAccept::~ThAccept() {}

void ThAccept::run() {
    //std::cout << "THREAD ACCEPT" << std::endl;
    std::vector<Socket> mySockets;

    Socket serverSocket;

    serverSocket.socket_bindAndListen("8080");



    Socket peer;
    serverSocket.socket_accept(&peer);

    return;



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



}