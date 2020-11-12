#include <iostream>
#include "Client.h"

int main(int argc, char* argv[]){
    if (argc > 1) {
        std::cout << argv[1] << std::endl;
    }

    Client client(argc, argv);
    try {
        client.run();
    } catch (int i) {
        std::cout << "ERROR" << std::endl;
    }

    return 0;
}
