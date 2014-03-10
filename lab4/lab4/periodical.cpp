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

Periodical::~Periodical(){
	
}

void Periodical::print()const{
	cout << setw(5) << amount << setw(4) << year << setw(2) << month
		<< setw(30) << title << endl;
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

Periodical* Periodical::create() {
    return new Periodical();
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
    return false;
}

bool Periodical::operator!=(const NodeData & right) const{
	return !(*this==right);
}