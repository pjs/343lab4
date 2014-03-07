//
//  hashable.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef HASHABLE_H
#define HASHABLE_H

#include <iostream>

using namespace std;

class Hashable {
    
public:
    virtual int hash() const = 0;
    
};

#endif
