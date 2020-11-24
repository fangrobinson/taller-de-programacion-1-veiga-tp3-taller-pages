#ifndef SOLUTION_PROCOLOEXCEPTION_H
#define SOLUTION_PROCOLOEXCEPTION_H

#include <exception>
#include <string>

class ProcoloException : public std::exception {
public:
    explicit ProcoloException(const std::string &errmsg);
    std::string strmsg();

private:
    std::string errmsg;
};

#endif //SOLUTION_PROCOLOEXCEPTION_H
