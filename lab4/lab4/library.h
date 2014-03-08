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
#include "user.h"

using namespace std;

class Library {
    
public:
    Library();
    ~Library();
    
    void addUser(User*);
    
private:
    BinTree Users;
    
};

#endif
