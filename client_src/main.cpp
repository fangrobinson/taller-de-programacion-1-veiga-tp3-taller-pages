#include <iostream>
#include "Client.h"
#include "../common_src/ArgumentsException.h"

int main(int argc, char* argv[]){
    if (argc > 1) {
        std::cout << argv[1] << std::endl;
    }

    Client client(argc, argv);
    try {
        client.run();
    } catch (ArgumentsException) {
        return 1;
    }
    catch (...) {
        std::cout << "UNEXPECTED ERROR" << std::endl;
    }

    return 0;
}
