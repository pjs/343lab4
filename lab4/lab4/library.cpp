//
//  library.cpp
//
//  Paul Simpson
//  Trevor Olson
//


#include "library.h"

//-----------------------------------------------------------------------------
// constructor

Library::Library() {

}

//-----------------------------------------------------------------------------
// destructor

Library::~Library() {

}

//-----------------------------------------------------------------------------
// addUser

void Library::addUser(User* userPtr) {
    Users.insert(userPtr);
}