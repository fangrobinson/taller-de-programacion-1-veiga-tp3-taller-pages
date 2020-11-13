#include "ArgumentsException.h"
#include <string>
#include <exception>

ArgumentsException::ArgumentsException(std::string errmsg) {
    this->errmsg = errmsg;
}
