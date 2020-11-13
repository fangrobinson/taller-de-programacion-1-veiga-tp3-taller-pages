#include <iostream>
#include "Server.h"

#include "../common_src/ArgumentsException.h"

int main(int argc, char* argv[]){
    Server server(argc, argv);
    try {
        server.run();
    } catch (ArgumentsException) {
        return 1;
    }
    catch (...) {
        std::cout << "UNEXPECTED ERROR" << std::endl;
    }

    return 0;
}
