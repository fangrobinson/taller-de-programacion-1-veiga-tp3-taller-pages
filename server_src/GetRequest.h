#ifndef SOLUTION_GETREQUEST_H
#define SOLUTION_GETREQUEST_H
#include "Request.h"

class GetRequest : public Request {
public:
    ~GetRequest();
    void Execute() override;
};

#endif //SOLUTION_GETREQUEST_H
