#ifndef TP3_COMMANDFACTORY_H
#define TP3_COMMANDFACTORY_H

#include "Command.h"
#include "ResourceManager.h"

class CommandFactory {
public:
    Command *getRequestCommand(std::string &metodo,
                               ResourceManager &resourceManager,
                               std::string &resource,
                               std::string &body);
};


#endif //TP3_COMMANDFACTORY_H
