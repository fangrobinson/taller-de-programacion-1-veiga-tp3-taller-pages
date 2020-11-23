#include <iostream>
#include "Server.h"

#include "../common_src/ArgumentsException.h"
#include "../common_src/SocketException.h"

int main(int argc, char* argv[]){
    Server server(argc, argv);
    try {
        server.run();
    } catch (ArgumentsException&) {
        return 1;
    } catch (SocketException& e) {
        std::cout << e.strmsg() << std::endl;
        return 1;
    }
    catch (...) {
        std::cout << "UNEXPECTED ERROR" << std::endl;
    }
    return 0;
}
