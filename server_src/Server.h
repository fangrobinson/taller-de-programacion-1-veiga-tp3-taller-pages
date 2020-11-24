#ifndef SOLUTION_SERVER_H
#define SOLUTION_SERVER_H

#include "../common_src/Socket.h"
#include "ThAccept.h"
#include "ResourceManager.h"

class Server {
private:
    ResourceManager resourceManager;
    Socket serverSocket;
    char *port;
    char *rootFile;
    ThAccept *acceptTh;

public:
    Server(int argc, char *argv[]);
    ~Server();
    void run();
};


#endif //SOLUTION_SERVER_H
