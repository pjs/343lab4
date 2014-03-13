//
//  item.cpp
//
//  Paul Simpson
//  Trevor Olson
//

#include "item.h"

//-----------------------------------------------------------------------------
// constructor

Item::Item(string title, int amount){
	this->title = title;
	this->amount = amount;
}

//-----------------------------------------------------------------------------
// destructor

Item::~Item() {
    
}

//-----------------------------------------------------------------------------
// addItem
// increments the amount of items available for this particular item by one

bool Item::addItem() {	
    amount++;
    return true;
}

//-----------------------------------------------------------------------------
// removeItem
// decreases the amount of items available for this item by one
// returns false if there are no more available

bool Item::removeItem() {
    if (amount > 0) {
        amount--;
        return true;
    }
    else {
        return false;
    }
}

