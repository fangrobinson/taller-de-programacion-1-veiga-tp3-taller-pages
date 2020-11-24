#include "ResourceManager.h"
#include <fstream>
#include <iostream>
#include <string>

ResourceManager::ResourceManager(){}

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

void ResourceManager::addRoot(char *fileName) {
    // entiendo que mi interfaz expuesta al publico no es thread safe
    // en cuanto termine las funcionalidades
    // minimas del trabajo, debería corregir esto
    std::string lineRead;
    std::stringstream buffer;
    std::ifstream file(fileName);
    if ( file )
    {
        buffer << file.rdbuf();
        file.close();
    }
    this->addResourceAt(buffer, "/");
}
