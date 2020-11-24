#ifndef TP3_GETCOMMAND_H
#define TP3_GETCOMMAND_H

#include <string>
#include "ResourceManager.h"

class GetCommand {
private:
    ResourceManager &resourceManager;
    std::string &resource;
public:
    GetCommand(ResourceManager &resourceManager, std::string &resource);
    std::string operator() ();
};

#endif //TP3_GETCOMMAND_H
