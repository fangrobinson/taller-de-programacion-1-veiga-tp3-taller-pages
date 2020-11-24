#ifndef TP3_POSTCOMMAND_H
#define TP3_POSTCOMMAND_H

#include "ResourceManager.h"
#include <string>

class PostCommand {
private:
    ResourceManager &resourceManager;
    std::string &resource;
    std::string &body;
public:
    PostCommand(ResourceManager &resourceManager,
                std::string &resource,
                std::string &body);
    std::string operator() ();
};

#endif //TP3_POSTCOMMAND_H
