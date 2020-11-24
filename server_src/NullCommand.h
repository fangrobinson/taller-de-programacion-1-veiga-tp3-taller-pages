#ifndef TP3_NULLCOMMAND_H
#define TP3_NULLCOMMAND_H

#include <string>
#include "Command.h"

class NullCommand : public Command {
private:
    std::string metodo;
public:
    ~NullCommand();
    explicit NullCommand(std::string &metodo);
    std::string operator() () override;
};


#endif //TP3_NULLCOMMAND_H
