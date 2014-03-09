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

bool Periodical::setData(istream & infile){
	infile.get();   
	getline(infile, title, ',');
	infile >> this->month;
	infile.get();   
	infile >> this->year;
	return true;
}
int Periodical::hash() const{
	return 'p' - 'a';
}

bool Periodical::operator<(const NodeData & right) const{
	const Periodical& book = static_cast<const Periodical&>(right);
	if(this->month < book.month) return true;
	if(this->year < book.year) return true;
	return false;
}

bool Periodical::operator<=(const NodeData & right) const{
	const Periodical& book = static_cast<const Periodical&>(right);
	if(this->month <= book.month) return true;
	if(this->year <= book.year) return true;
	return false;
}


bool Periodical::operator>(const NodeData & right) const{
	const Periodical& book = static_cast<const Periodical&>(right);
	if(this->month > book.month) return true;
	if(this->year > book.year) return true;
	return false;
}

bool Periodical::operator>=(const NodeData & right) const{
	const Periodical& book = static_cast<const Periodical&>(right);
	if(this->month >= book.month) return true;
	if(this->year >= book.year) return true;
	return false;
}

bool Periodical::operator==(const NodeData & right) const{
	const Periodical& book = static_cast<const Periodical&>(right);
	if(this->month == book.month && this->year == book.year) return true;
}

bool Periodical::operator!=(const NodeData & right) const{
	return !(*this==right);
}