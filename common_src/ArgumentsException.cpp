#include "ArgumentsException.h"
#include <string>
#include <exception>

ArgumentsException::ArgumentsException(const std::string &errmsg) {
    this->errmsg = errmsg;
}
