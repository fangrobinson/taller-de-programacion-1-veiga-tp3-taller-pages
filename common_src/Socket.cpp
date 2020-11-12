#include "Socket.h"
#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/socket.h>

Socket::Socket() {
    this->mySocket = -1;
}

Socket::~Socket() {
    if (this->mySocket != -1) {
        ::shutdown(this->mySocket, SHUT_RDWR);
        ::close(this->mySocket);
    }
}


void Socket::bindAndListen(const char *port) {
    struct addrinfo hints;
    struct addrinfo *results, *rp;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    printf("%s", port);
    port = "8088";

    if (getaddrinfo(0, port, &hints, &results)) {
        printf("1");
        throw int(1);
    }

    int sfd;
    int val = 1;

    for (rp = results; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype,
                     rp->ai_protocol);
        if (sfd == -1)
            continue;
        setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
        if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
            break;
        printf("SOCKET INV");
        printf("%d", sfd);
        ::close(sfd);
    }


    if (rp == NULL) {
        freeaddrinfo(results);
        printf("2");
        throw int(1);
    }

    this->mySocket = sfd;

    int valid_listen = listen(this->mySocket, 1);
    if (valid_listen != 0) {
        freeaddrinfo(results);
        printf("3");
        throw int(1);
    }

    freeaddrinfo(results);
}


void Socket::connect(const char *server, const char *port) {
    struct addrinfo hints;
    struct addrinfo *results, *rp;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    int status = getaddrinfo(server, port, &hints, &results);
    if (status == 1) {
        throw int(1);
    }

    int sfd;
    int val = 1;

    for (rp = results; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype,
                     rp->ai_protocol);
        if (sfd == -1)
            continue;
        setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
        if (::connect(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
            break;
        ::close(sfd);
    }


    if (rp == NULL) {
        freeaddrinfo(results);
        throw int(1);
    }


    this->mySocket = sfd;

    freeaddrinfo(results);
}


void Socket::accept(Socket *aSocket) {
    aSocket->mySocket = ::accept(this->mySocket, NULL, NULL);
    if (aSocket->mySocket == -1) {
        throw int(1);
    }
}

void Socket::close() {
    ::shutdown(this->mySocket, SHUT_RDWR);
    ::close(this->mySocket);
}

/*
void Socket::shutdown() {
    return;
    //::shutdown(this->mySocket, SHUT_RDWR);
}
*/

int Socket::send(const char *buffer, unsigned int length) {
    int bytes_sent = 0;
    int socket_open = 1;

    while (length >= bytes_sent && socket_open) {
        int bytes_to_add = ::send(this->mySocket, (buffer + bytes_sent),
                                length - bytes_sent, 0);
        if (bytes_to_add > 0){
            bytes_sent += bytes_to_add;
        } else if (bytes_to_add == 0){
            socket_open = 0;
        } else {
            return -1;
        }
    }

    return bytes_sent;
}

int Socket::receive(char *buffer, unsigned int length) {
    int bytes_received = 0;
    int socket_open = 1;

    while (length > bytes_received && socket_open == 1) {
        int bytes_to_add = ::recv(this->mySocket, &buffer[bytes_received],
                                length - bytes_received, 0);

        if (bytes_to_add > 0){
            bytes_received += bytes_to_add;
        } else {
            socket_open = bytes_to_add;
        }
    }
    return bytes_received;
}