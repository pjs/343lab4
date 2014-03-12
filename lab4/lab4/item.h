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

const static int TITLE_OUTPUT_WIDTH = 35;
const static int AVAIL_OUTPUT_WIDTH = 6;
const static int YEAR_OUTPUT_WIDTH = 4; 
const static int AMOUNT = 5;

class Item : public Hashable,  public NodeData {

protected:
    string title;
    int amount;
    
public:
    Item(string = "", int = 0);
    virtual ~Item();
    virtual Item* create() = 0;
    
    bool addItem();
    bool removeItem();
    
    
    
};

#endif


