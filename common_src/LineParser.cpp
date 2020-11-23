#include "LineParser.h"
#include <iostream>
#include <sstream>
#include <string>

LineParser::LineParser() {}
LineParser::~LineParser() {}


void LineParser::parseFirstLine(std::string *line,
                                  std::string *method,
                                  std::string *resource,
                                  std::string *protocol) {
    std::string firstLine;
    *line = firstLine;
    std::getline(std::cin, firstLine);
    std::stringstream ss(firstLine);
    ss >> *method;
    ss >> *resource;
    ss >> *protocol;
}


void LineParser::parseHeader(std::string *line,
                               unsigned int *contentLength) {
    std::string aLine;
    *line = aLine;
    while (std::getline(std::cin, aLine) && !aLine.empty()) {
        std::stringstream ss(aLine);
        std::string clave;
        std::getline(ss, clave, ':');
        if (clave != "Content-Length") {
            continue;
        }
        ss >> *contentLength;
    }
}

void LineParser::parseBody() {

}
