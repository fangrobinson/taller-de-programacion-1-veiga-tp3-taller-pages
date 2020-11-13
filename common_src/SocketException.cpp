#include "SocketException.h"
#include <string>
#include <exception>

SocketException::SocketException(std::string errmsg) {
    this->errmsg = errmsg;
}

std::string SocketException::strmsg() {
    return this->errmsg;
}

/*
const std::string SocketException::what() {
    return this->errmsg;
}
*/
