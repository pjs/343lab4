//
//  userfactory.cpp
//
//  Paul Simpson
//  Trevor Olson
//

#include "userfactory.h"

//-----------------------------------------------------------------------------
// constructor

UserFactory::UserFactory() {
    objFactory[0] = new User();
}

//-----------------------------------------------------------------------------
// destructor

UserFactory::~UserFactory() {
    for (int i = 0; i < FACTORY_SIZE; i++) {
        delete objFactory[i];
        objFactory[i] = NULL;
    }
}

//-----------------------------------------------------------------------------
// create
// returns new user type that is requested

User* UserFactory::createIt(int i) {
    return objFactory[i]->create();
}

