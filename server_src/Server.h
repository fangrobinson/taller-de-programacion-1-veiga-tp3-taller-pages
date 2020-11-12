//
// Created by FANG on 10/11/2020.
//

#ifndef SOLUTION_SERVER_H
#define SOLUTION_SERVER_H

#include "../common_src/Socket.h"

class Server {
private:
    //esperarNuevosClientes ciclo accept
    //limpiarThClientZombies ciclo isDead -> .join()
    //terminarClientes

    Socket serverSocket;

public:
    Server();
    void run();
};


#endif //SOLUTION_SERVER_H
