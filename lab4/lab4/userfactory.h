//
//  userfactory.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef USERFACTORY_H
#define USERFACTORY_H

#include <iostream>
#include "user.h"

using namespace std;

//-----------------------------------------------------------------------------
// class UserFactory
//
//
// The factory for users. This class creates new, empty user objects
//
// Assumptions:
// -user gives the appropiate hash value, otherwise results may vary
//
//-----------------------------------------------------------------------------
class UserFactory {
    
public:
    UserFactory();
    ~UserFactory();
    User* createIt(int);
    
private:
    static const int FACTORY_SIZE = 1;
    User* objFactory[FACTORY_SIZE];
};

#endif

