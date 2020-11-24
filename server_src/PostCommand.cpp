#include "PostCommand.h"

#include <string>
#include <sstream>

PostCommand::~PostCommand() {}

PostCommand::PostCommand(ResourceManager &resourceManager,
                         std::string &resource,
                         std::string &body) :
        resourceManager(resourceManager),
        resource(resource),
        body(body) {}

std::string PostCommand::operator() () {
    if (this->resource == "/") {
        return "HTTP/1.1 403 FORBIDDEN\n\n\n”";
    }

    resourceManager.addResourceAt(this->body,
                                  this->resource);
    std::stringstream client_output;
    client_output << "HTTP/1.1 200 OK\n\n";
    client_output << body;

    return client_output.str();
}
