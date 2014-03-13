//
//  userfactory.h
//
//  Paul Simpson
//  Trevor Olson
//

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

#ifndef USERFACTORY_H
#define USERFACTORY_H

#include <iostream>
#include "user.h"

using namespace std;

class UserFactory {
    
public:
    UserFactory();        // constructor
    ~UserFactory();       // destructor
    User* createIt(int);  // returns copy of requested user type
    
private:
    static const int FACTORY_SIZE = 1;  // available types of users
    User* objFactory[FACTORY_SIZE];     // factory of objects
};

#endif

