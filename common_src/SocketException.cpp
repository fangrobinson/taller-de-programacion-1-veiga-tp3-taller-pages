#include "SocketException.h"
#include <string>
#include <exception>

SocketException::SocketException(std::string errmsg) {
    this->errmsg = errmsg;
}


/*
const std::string SocketException::what() {
    return this->errmsg;
}
*/
