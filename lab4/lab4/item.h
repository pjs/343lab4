//
//  item.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class Item
//
// An item is a hashable class and a NodeData. Item is an abstract class and
// has different classes of items.
//
//
// Assumptions:
// - all items have one title
// - all items have the amount of 5 when inciated
// - item infile is formated properly
//-----------------------------------------------------------------------------

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include "hashable.h"
#include "nodedata.h"

using namespace std;

const static int TITLE_OUTPUT_WIDTH = 35;  // title width
const static int AVAIL_OUTPUT_WIDTH = 6;   // avail width
const static int YEAR_OUTPUT_WIDTH = 4;    // year width
const static int AMOUNT = 5;               // amount width

class Item : public Hashable,  public NodeData {

protected:
    string title;  // title of the item
    int amount;    // amount available in the library
    
public:
    Item(string = "", int = AMOUNT);   // constructor
    virtual ~Item();              // destructor
    virtual Item* create() = 0;   // clone item (for use in factory)
    
    bool addItem();    // increase item amount by one
    bool removeItem(); // decrease item amount by one
    
};

#endif


