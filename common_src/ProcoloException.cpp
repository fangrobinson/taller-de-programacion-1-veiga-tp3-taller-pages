#include "ProcoloException.h"

#include <string>
#include <exception>

ProcoloException::ProcoloException(const std::string &errmsg) {
    this->errmsg = errmsg;
}

std::string ProcoloException::strmsg() {
    return this->errmsg;
}
