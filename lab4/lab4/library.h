//
//  library.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class Library
//
// A library contains zero to many items and users
//
//
// Assumptions:
// - items are hashable
//
//-----------------------------------------------------------------------------

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "bintree.h"

using namespace std;

class Item;
class User;

class Library {
    
public:
    Library();  // constructor
    ~Library(); // destructor
    
    BinTree& getItems(int);  // get items in the library
    BinTree& getUsers();     // get users in the library

private:
    static const int FACTORY_SIZE = 26;  // size of item factory
    
    // collections for users and items
    BinTree users;
    BinTree items[FACTORY_SIZE];
    
    
};

#endif


