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

//-----------------------------------------------------------------------------
// class CommandFactory
//
// The factory for commands. This class is designed to create different type of
// command objects
//
//
// Assumptions:
// - user gives the appropiate hash value, otherwise results may vary
//
//-----------------------------------------------------------------------------
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


