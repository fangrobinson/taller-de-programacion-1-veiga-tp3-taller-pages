#include "GetCommand.h"

#include <string>
#include <sstream>


GetCommand::GetCommand(ResourceManager &resourceManager, std::string &resource) :
                    resourceManager(resourceManager),
                    resource(resource) {}

std::string GetCommand::operator() () {
    std::string s = resourceManager.getResourceAt(this->resource);
    if (s.size() == 0){
        return "HTTP/1.1 404 NOT FOUND\n\n";
    }
    std::stringstream client_output;
    client_output << "HTTP/1.1 200 OK\n";
    client_output << "Content-Type: text/html\n\n";
    client_output << s;
    return client_output.str();
}
