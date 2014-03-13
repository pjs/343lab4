//
//  itemfactory.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class ItemFactory
//
// This is a factory to create new, empty Item objects.
//
// Assumptions:
// - user gives the appropiate hash value for item, otherwise results may vary
//
//-----------------------------------------------------------------------------

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <iostream>
#include "item.h"

using namespace std;

class ItemFactory {

public:
    ItemFactory();           // constructor
    ~ItemFactory();          // destructor
    Item* createIt(int);     // returns clone of item
    bool isValid(int) const; // checks if item can be cloned
    
private:
    static const int FACTORY_SIZE = 26;  // size of item factory
    Item* objFactory[FACTORY_SIZE];  // array of item objects
};

#endif


