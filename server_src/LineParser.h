#ifndef SOLUTION_LINEPARSER_H
#define SOLUTION_LINEPARSER_H

#include <string>

class LineParser {
public:
    LineParser();
    ~LineParser();
    void parseFirstLine(std::string &line,
                        std::string &method,
                        std::string &resource,
                        std::string &protocol);
    void skipHeader(std::stringstream &inputRequest);
    void parseBody(std::stringstream &inputRequest, std::string &body);
};


#endif //SOLUTION_LINEPARSER_H
