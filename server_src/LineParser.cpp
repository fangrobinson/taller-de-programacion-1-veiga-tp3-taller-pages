#include "LineParser.h"
#include <iostream>
#include <sstream>
#include <string>

LineParser::LineParser() {}
LineParser::~LineParser() {}


void LineParser::parseFirstLine(std::string &line,
                                  std::string &method,
                                  std::string &resource,
                                  std::string &protocol) {
    std::stringstream ss(line);
    ss >> method;
    ss >> resource;
    ss >> protocol;
}
