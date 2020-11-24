#ifndef SOLUTION_ARGUMENTSEXCEPTION_H
#define SOLUTION_ARGUMENTSEXCEPTION_H


#include <exception>
#include <string>

class ArgumentsException : public std::exception {
public:
    explicit ArgumentsException(std::string errmsg);

private:
    std::string errmsg;
};


#endif //SOLUTION_ARGUMENTSEXCEPTION_H
