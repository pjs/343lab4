//
//  item.cpp
//
//  Paul Simpson
//  Trevor Olson
//



#include "item.h"

Item::Item( int amount){
	this->title = title;
	this->amount = amount;
}

bool Item::operator<(const Item & right) const{
	return this->title < right.title;
}

bool Item::operator>(const Item & right) const{
	return this->title > right.title;
}