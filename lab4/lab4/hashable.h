//
//  hashable.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef HASHABLE_H
#define HASHABLE_H

#include <iostream>

//-----------------------------------------------------------------------------
// class hashable 
//
// An abstract class that allows other items to be hashed. 
//
// Assumptions:
// - each hashable class implements their own hash function 
//-----------------------------------------------------------------------------
using namespace std;

class Hashable{
    
public:
    virtual int hash() const = 0; 
};

#endif


