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

