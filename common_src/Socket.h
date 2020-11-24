#ifndef SOLUTION_SOCKET_H
#define SOLUTION_SOCKET_H


class Socket {
private:
    int mySocket;
    void setFd(int sfd);
public:
    Socket();
    ~Socket();

    Socket(const Socket& aSocket) = delete;
    //Socket(const Socket&& aSocket) noexcept ;
    Socket& operator=(const Socket&& aSocket);
    Socket* accept();
    void bindAndListen(const char *port);
    void connect(const char *server, const char *port);
    //void accept(Socket *socket_to_accept);
    //void shutdown();
    void close();

    void shutdownWrite();

    int send(const char *buffer, unsigned int length);
    int receive(char *buffer, unsigned int length);
};


#endif //SOLUTION_SOCKET_H
