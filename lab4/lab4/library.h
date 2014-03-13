//
//  library.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "bintree.h"

using namespace std;

class Item;
class User;

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
class Library {
    
public:
    Library();
    ~Library();
    
    BinTree& getItems(int);
    BinTree& getUsers();

private:
    static const int FACTORY_SIZE = 26;
    BinTree users;
    BinTree items[FACTORY_SIZE];
    
    
};

#endif


