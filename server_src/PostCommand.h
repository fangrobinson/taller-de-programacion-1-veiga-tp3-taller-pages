#ifndef TP3_POSTCOMMAND_H
#define TP3_POSTCOMMAND_H

#include "ResourceManager.h"
#include <string>
#include "Command.h"

class PostCommand : public Command {
private:
    ResourceManager &resourceManager;
    std::string &resource;
    std::string &body;
public:
    ~PostCommand();
    PostCommand(ResourceManager &resourceManager,
                std::string &resource,
                std::string &body);
    std::string operator() () override;
};

#endif //TP3_POSTCOMMAND_H
