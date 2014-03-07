//
//  item.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "hashable.h"

using namespace std;

class Item : public Hashable {
    
protected:
    string title;
    int amount;
    
public:
    Item(string = "", int = 0);
  //  virtual ~Item();
    
    virtual int hash() const = 0;
 /*   virtual bool operator<(const Item &) const = 0;
    virtual bool operator>(const Item &) const = 0;
    virtual bool operator<=(const Item &) const = 0;
    virtual bool operator>=(const Item &) const = 0; */
    
};

#endif
