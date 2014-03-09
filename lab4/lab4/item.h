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
#include "nodedata.h"

using namespace std;

class Item : public Hashable,  public NodeData{
    
protected:
    string title;
    int amount;
    
public:
    Item(string = "", int = 0);
  //  virtual ~Item();
    virtual Item* create() = 0;
};

#endif
