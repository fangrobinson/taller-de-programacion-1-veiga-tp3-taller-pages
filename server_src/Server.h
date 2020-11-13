#ifndef SOLUTION_SERVER_H
#define SOLUTION_SERVER_H

#include "../common_src/Socket.h"

class Server {
private:
    //esperarNuevosClientes ciclo accept
    //limpiarThClientZombies ciclo isDead -> .join()
    //terminarClientes
    Socket serverSocket;
    char *port;
    char *rootFile;

public:
    Server(int argc, char *argv[]);
    void run();
};


#endif //SOLUTION_SERVER_H
