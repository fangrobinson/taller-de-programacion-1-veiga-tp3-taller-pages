#include "Server.h"

#include <iostream>

int main(int argc, char* argv[]){
    Server server(argc, argv);
    try {
        server.run();
    } catch (int i) {
        //printf("EROR");
        std::cout << "ERROR" << std::endl;
    }

    return 0;
}
