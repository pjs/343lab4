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

class Library {
    
public:
    Library();
    ~Library();
    
    void displayUsers() const; // remove later
    
    BinTree& getItems(int);
    BinTree& getUsers();

private:
    static const int FACTORY_SIZE = 26;
    BinTree users;
    BinTree items[FACTORY_SIZE];
    
    
};

#endif


