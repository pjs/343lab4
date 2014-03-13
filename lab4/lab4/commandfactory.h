//
//  commandfactory.h
//
//  Paul Simpson
//  Trevor Olson
//

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

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "command.h"

using namespace std;

class CommandFactory {
    
public:
    CommandFactory();        // destructor
    ~CommandFactory();       // constructor
    Command* createIt(int);  // builds requested object
    bool isValid(int) const; // checks if object can be uilt
    
private:
    static const int FACTORY_SIZE = 26;  // room for objects in factory
    Command* objFactory[FACTORY_SIZE];   // array of commands in factory
    
};

#endif


