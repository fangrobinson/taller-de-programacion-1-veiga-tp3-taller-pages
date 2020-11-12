#include "Server.h"

#include <iostream>

int main(int argc, char* argv[]){
    Server s;
    try {
        s.run();
    } catch (int i) {
        //printf("EROR");
        std::cout << "ERROR" << std::endl;
    }

    return 0;
}
