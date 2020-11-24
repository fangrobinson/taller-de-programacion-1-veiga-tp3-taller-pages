#ifndef SOLUTION_SOCKETEXCEPTION_H
#define SOLUTION_SOCKETEXCEPTION_H

#include <exception>
#include <string>

class SocketException : public std::exception {
public:
    explicit SocketException(const std::string &errmsg);
    std::string strmsg();

private:
    std::string errmsg;
};


#endif //SOLUTION_SOCKETEXCEPTION_H
