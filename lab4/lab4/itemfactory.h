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

class ItemFactory {
    
public:
    ItemFactory();
    ~ItemFactory();
    Item* createIt(int);
    bool isValid(int) const;
    
private:
    Item* objFactory[26];
};

#endif


