#include "CommandFactory.h"

#include "NullCommand.h"
#include "GetCommand.h"
#include "PostCommand.h"
#include <string>
#include "ResourceManager.h"


Command * CommandFactory::getRequestCommand(std::string &metodo,
                           ResourceManager &resourceManager,
                           std::string &resource,
                           std::string &body) {
    if (metodo == "GET") {
        return new GetCommand(resourceManager, resource);
    }
    if (metodo == "POST") {
        return new PostCommand(resourceManager, resource, body);
    }
    return new NullCommand(metodo);
}
