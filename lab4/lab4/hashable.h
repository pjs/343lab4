//
//  hashable.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class Hashable
//
// An abstract class that allows other items to be hashed.
//
// Assumptions:
// - each hashable class implements their own hash function
//-----------------------------------------------------------------------------

#ifndef HASHABLE_H
#define HASHABLE_H

#include <iostream>

using namespace std;

class Hashable {
    
public:
    virtual int hash() const = 0; // hash of object type
};

#endif


