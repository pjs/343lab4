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

class UserFactory {
    
public:
    UserFactory();
    ~UserFactory();
    User* createIt(int);
    
private:
    User* objFactory[1];
};

#endif

