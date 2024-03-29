#include "Socket.h"
#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/socket.h>

#include "SocketException.h"

Socket::Socket() {
    this->mySocket = -1;
}

Socket &Socket::operator=(const Socket &&aSocket) {
    this->mySocket = aSocket.mySocket;
    return *this;
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

    if (getaddrinfo(0, port, &hints, &results)) {
        throw SocketException("ERR: socket bind could not resolve address.");
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
        ::close(sfd);
    }


    if (rp == NULL) {
        freeaddrinfo(results);
        throw SocketException("ERR: socket bind could not bind to any hint.");
    }

    this->mySocket = sfd;

    int valid_listen = listen(this->mySocket, 1);
    if (valid_listen != 0) {
        freeaddrinfo(results);
        throw SocketException("ERROR: socket bind could not listen");
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

    if (getaddrinfo(server, port, &hints, &results)) {
        freeaddrinfo(results);
        throw SocketException("ERR: socket connect could not resolve address.");
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
        throw SocketException("ERR: socket connect could not connect to hint.");
    }


    this->mySocket = sfd;

    freeaddrinfo(results);
}

void Socket::setFd(int sfd) {
    this->mySocket = sfd;
}

Socket* Socket::accept() {
    int sfd;
    if (this->mySocket) {
        sfd = ::accept(this->mySocket, NULL, NULL);
        if (sfd == -1) {
            throw SocketException("ERR: socket accept could not accept");
        }
    } else {
        throw SocketException("ERR: socket accept not listening");
    }
    Socket *s = new Socket();
    s->setFd(sfd);
    return s;
}



void Socket::close() {
    if (this->mySocket != -1) {
        ::shutdown(this->mySocket, SHUT_RDWR);
        ::close(this->mySocket);
    }
}


void Socket::shutdownWrite() {
    ::shutdown(this->mySocket, SHUT_WR);
}


int Socket::send(const char *buffer, unsigned int length) {
    unsigned int bytes_sent = 0;
    int socket_open = 1;

    while (length >= bytes_sent && socket_open) {
        int bytes_to_add = ::send(this->mySocket, (buffer + bytes_sent),
                                length - bytes_sent, MSG_NOSIGNAL);
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
    unsigned int bytes_received = 0;
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
