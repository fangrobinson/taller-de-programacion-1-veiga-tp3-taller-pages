#ifndef SOLUTION_CLIENT_H
#define SOLUTION_CLIENT_H

#include "../common_src/Socket.h"


class Client {
public:
    Client(int argc, char* argv[]);
    ~Client();
    void run();

private:
    Socket socket;
    char *host;
    char *port;


};


#endif //SOLUTION_CLIENT_H
