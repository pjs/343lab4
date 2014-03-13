//
//  itemfactory.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <iostream>
#include "item.h"

using namespace std;

//-----------------------------------------------------------------------------
// class Item Factory
//
// This is a factory to create new, empty Item objects. 
//
// Assumptions:
// - user gives the appropiate hash value for item, otherwise results may vary
//
//-----------------------------------------------------------------------------
class ItemFactory {

public:
    ItemFactory();
    ~ItemFactory();
    Item* createIt(int);
    bool isValid(int) const;
    
private:
    static const int FACTORY_SIZE = 26;
    Item* objFactory[FACTORY_SIZE];
};

#endif


