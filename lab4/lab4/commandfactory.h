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
    Command* objFactory[26];
};

#endif
