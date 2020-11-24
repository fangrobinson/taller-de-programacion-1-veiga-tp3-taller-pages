#ifndef TP3_GETCOMMAND_H
#define TP3_GETCOMMAND_H

#include <string>
#include "ResourceManager.h"
#include "Command.h"

class GetCommand : public Command{
private:
    ResourceManager &resourceManager;
    std::string &resource;
public:
    ~GetCommand();
    GetCommand(ResourceManager &resourceManager, std::string &resource);
    std::string operator() () override;
};

#endif //TP3_GETCOMMAND_H
