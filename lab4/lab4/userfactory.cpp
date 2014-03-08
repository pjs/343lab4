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
    for (int i = 0; i < 1; i++) {
        delete objFactory[i];
        objFactory[i] = NULL;
    }
}

//-----------------------------------------------------------------------------
// create

User* UserFactory::createIt(int i) {
    return objFactory[i]->create();
}