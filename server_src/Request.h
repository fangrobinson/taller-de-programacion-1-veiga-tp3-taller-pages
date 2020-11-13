#ifndef SOLUTION_REQUEST_H
#define SOLUTION_REQUEST_H


class Request {
public:
    virtual ~Request();
    virtual void Execute();
};

#endif //SOLUTION_REQUEST_H
