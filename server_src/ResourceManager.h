#ifndef TP3_RESOURCEMANAGER_H
#define TP3_RESOURCEMANAGER_H

#include <string>
#include <sstream>
#include <mutex>
#include <unordered_map>

class ResourceManager {
private:
    std::mutex m;
    std::unordered_map<std::string, std::string> resources;
    
public:
    explicit ResourceManager(std::string fileName);
    ResourceManager() = delete;
    ~ResourceManager();
    void addResourceAt(std::string &resourceContents, std::string resourceName);
    void addResourceAt(std::stringstream &resourceContents,
                       std::string resourceName);
    std::string getResourceAt(std::string resourceName);
};


#endif //TP3_RESOURCEMANAGER_H
