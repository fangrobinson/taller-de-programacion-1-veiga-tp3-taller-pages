#ifndef SOLUTION_POSTREQUEST_H
#define SOLUTION_POSTREQUEST_H

#include "Request.h"

class PostRequest : public Request{
public:
    ~PostRequest();
    void Execute() override;
};

#endif //SOLUTION_POSTREQUEST_H
