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

//-----------------------------------------------------------------------------
// findUser

bool Library::findUser(const User &search, NodeData *&result) const {
    return users.retrieve(search, result);
}

//-----------------------------------------------------------------------------
// findItem

bool Library::findItem(const Item &search, NodeData *&result) const {
    int hash = search.hash();
    
    return items[hash].retrieve(search, result);
}

//-----------------------------------------------------------------------------
//displayUsers

void Library::displayUsers()const{
	cout << users << endl;
    
}

//-----------------------------------------------------------------------------
// getItems

BinTree& Library::getItems(int i) {
	return items[i];
}

//-----------------------------------------------------------------------------
// getUsers

BinTree& Library::getUsers() {
	return users;
}