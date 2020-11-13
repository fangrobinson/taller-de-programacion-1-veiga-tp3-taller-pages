//
// Created by FANG on 12/11/2020.
//

#ifndef SOLUTION_SOCKETEXCEPTION_H
#define SOLUTION_SOCKETEXCEPTION_H

#include <exception>
#include <string>

class SocketException : public std::exception {
public:
    SocketException(std::string errmsg);
    //std::string what();

private:
    std::string errmsg;
};


#endif //SOLUTION_SOCKETEXCEPTION_H
