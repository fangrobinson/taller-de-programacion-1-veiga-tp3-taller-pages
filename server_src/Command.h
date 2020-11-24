//
// Created by robinson on 24/11/20.
//

#ifndef TP3_COMMAND_H
#define TP3_COMMAND_H

#include <string>

class Command {
public:
    virtual ~Command();
    virtual std::string operator()() = 0;
};


#endif //TP3_COMMAND_H
