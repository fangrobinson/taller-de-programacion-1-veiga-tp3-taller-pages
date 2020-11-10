#ifndef SOLUTION_SOCKET_H
#define SOLUTION_SOCKET_H


class Socket {
private:
    int socket;
public:
    Socket();
    ~Socket();
    //Socket() = delete;
    Socket(const Socket&) = delete;
    int bindAndListen(const char *port);
    int socket_connect(const char *server, const char *port);
    int socket_accept(Socket socket_to_accept);
    void socket_shutdown();

    int socket_send(const char *buffer, unsigned int length);
    int socket_receive(char *buffer, unsigned int length);
};


#endif //SOLUTION_SOCKET_H
