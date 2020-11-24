#include "SocketException.h"
#include <string>
#include <exception>

SocketException::SocketException(const std::string &errmsg) {
    this->errmsg = errmsg;
}

std::string SocketException::strmsg() {
    return this->errmsg;
}
