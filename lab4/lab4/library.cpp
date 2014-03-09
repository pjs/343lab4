//
//  library.cpp
//
//  Paul Simpson
//  Trevor Olson
//


#include "library.h"
#include "item.h"
#include "user.h"

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
    users.insert(userPtr);
}

//-----------------------------------------------------------------------------
// addItem

void Library::addItem(Item* itemPtr) {
    int hash = itemPtr->hash();
    
    items[hash].insert(itemPtr);
}