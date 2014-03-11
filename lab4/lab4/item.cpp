//
//  item.cpp
//
//  Paul Simpson
//  Trevor Olson
//



#include "item.h"

Item::Item(string title, int amount){
	this->title = title;
	this->amount = amount;
}

Item::~Item() {
    
}

bool Item::addItem() {	
    amount++;
    return true;
}

bool Item::removeItem() {
    if (amount > 0) {
        amount--;
        return true;
    }
    else {
        return false;
    }
}

