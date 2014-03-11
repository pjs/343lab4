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

    void addUser(User*);
    void addItem(Item*);
    bool findUser(const User &, NodeData *&) const;
    bool findItem(const Item &, NodeData *&) const;
    
    
	void displayLibrary() const;
    void displayUsers() const;
    
    BinTree& getItems(int);
    BinTree& getUsers();

private:
    BinTree users;
    BinTree items[26];
    
};

#endif
