#include "NullCommand.h"
#include <sstream>
#include <string>

NullCommand::~NullCommand() noexcept {}

NullCommand::NullCommand(const std::string &metodo) : metodo(metodo) {}

std::string NullCommand::operator() () {
    std::stringstream out;
    out << "HTTP/1.1 405 METHOD NOT ALLOWED\n\n";
    out << this->metodo;
    out << " es un comando desconocido\n";
    return out.str();
}
