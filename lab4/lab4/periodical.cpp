//
//  periodical.cpp
//
//  Paul Simpson
//  Trevor Olson
//


#include "periodical.h"

Periodical::Periodical(string title, int amout, int month, int year)
	:Item(title, amount){
	
	this->month = month;
	this->year = year;
}
int Periodical::hash() const{
	return 'p' - 'a';
}

bool Periodical::operator<(const Item &) const{
	
}