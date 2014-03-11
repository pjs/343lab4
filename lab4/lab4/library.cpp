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
//displayLibrary

void Library::displayLibrary()const{
	int item;
	cout << "Fiction:" << endl << setw(5) << "AVAIL" << setw(20) << "AUTHOR"
    << setw(30) << "TITLE" << setw(4) << "YEAR" << endl;
	item = 'f' - 'a';
	cout << items[item];
    
	cout << "Youth:" << endl << setw(5) << "AVAIL" << setw(20)
    << "AUTHOR" << setw(30) << "TITILE" << setw(4) << "YEAR" << endl;
	item = 'y' - 'a';
	cout << items[item];
    
	cout << "Periodicals:" << endl << setw(5) << "AVAIL" << setw(4)
    << "YEAR" << setw(2) << "MO" << setw(30) << "TITLE" << endl;
	item = 'p' - 'a';
	cout << items[item];
    
    
    
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