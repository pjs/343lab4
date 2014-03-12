//
//  commandfactory.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "command.h"

using namespace std;

class CommandFactory {
    
public:
    CommandFactory();
    ~CommandFactory();
    Command* createIt(int);
    bool isValid(int) const;
    
private:
    static const int FACTORY_SIZE = 26;
    Command* objFactory[FACTORY_SIZE];
    
};

#endif


