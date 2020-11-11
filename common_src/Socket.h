#ifndef SOLUTION_SOCKET_H
#define SOLUTION_SOCKET_H


class Socket {
private:
    int mySocket;
public:
    Socket();
    ~Socket();

    Socket(const Socket&) = delete;
    void socket_bindAndListen(const char *port);
    void socket_connect(const char *server, const char *port);
    void socket_accept(Socket *socket_to_accept);
    void socket_shutdown();

    int socket_send(const char *buffer, unsigned int length);
    int socket_receive(char *buffer, unsigned int length);
};


#endif //SOLUTION_SOCKET_H
