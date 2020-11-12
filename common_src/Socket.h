#ifndef SOLUTION_SOCKET_H
#define SOLUTION_SOCKET_H


class Socket {
private:
    int mySocket;
public:
    Socket();
    ~Socket();

    Socket(const Socket&) = delete;
    void bindAndListen(const char *port);
    void connect(const char *server, const char *port);
    void accept(Socket *socket_to_accept);
    //void shutdown();
    void close();

    int send(const char *buffer, unsigned int length);
    int receive(char *buffer, unsigned int length);
};


#endif //SOLUTION_SOCKET_H
