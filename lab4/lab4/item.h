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

using namespace std;

class Item {
    
protected:
    string title;
    int amount;
    
public:
    Item(string, int);
    virtual ~Item();
    
    virtual bool operator<(const Item &);
    virtual bool operator>(const Item &);
    virtual bool operator<=(const Item &);
    virtual bool operator>=(const Item &);
    
};

#endif
