#include "ResourceManager.h"
#include <fstream>
#include <string>

ResourceManager::ResourceManager(std::string fileName){
    std::stringstream buffer;
    std::ifstream file(fileName);
    if ( file )
    {
        buffer << file.rdbuf();
        file.close();
    }
    this->resources["/"] = buffer.str().c_str();
}

ResourceManager::~ResourceManager(){}

void ResourceManager::addResourceAt(std::stringstream &resourceContents,
                                    std::string resourceName) {
    const std::lock_guard<std::mutex> lockGuard(this->m);
    this->resources[resourceName] = resourceContents.str().c_str();
}

void ResourceManager::addResourceAt(std::string &resourceContents,
                                    std::string resourceName) {
    const std::lock_guard<std::mutex> lockGuard(this->m);
    this->resources[resourceName] = resourceContents.c_str();
}

std::string ResourceManager::getResourceAt(std::string resourceName) {
    const std::lock_guard<std::mutex> lockGuard(this->m);
    return std::string(this->resources[resourceName]);
}
