//
//  periodical.cpp
//
//  Paul Simpson
//  Trevor Olson
//

#include "periodical.h"

//-----------------------------------------------------------------------------
// constructor

Periodical::Periodical(string title, int amount, int month, int year) :
    Item() {
	
	this->month = month;
	this->year = year;
}

//-----------------------------------------------------------------------------
// destructor

Periodical::~Periodical() {
	
}

//-----------------------------------------------------------------------------
// print
// displays information about the item; if parameter is true, amount available
// is not shown

void Periodical::print(bool partial) const {
	if(!partial){
		cout << " " << setw(AVAIL_OUTPUT_WIDTH) << amount; 
	}
	cout << setw(YEAR_OUTPUT_WIDTH) << year << " " << setw(MO_OUTPUT_WIDTH) << 
		month << " " << left << setw(TITLE_OUTPUT_WIDTH) << 
		title.substr(0,TITLE_OUTPUT_WIDTH)  << endl;
}

//-----------------------------------------------------------------------------
// printHeader
// display header information for the periodical

void Periodical::printHeader() const {
	cout << "Periodicals:" << endl << setw(AVAIL_OUTPUT_WIDTH) << "AVAIL" << 
		setw(YEAR_OUTPUT_WIDTH) << " YEAR" << setw(MO_OUTPUT_WIDTH) << " MO"
		<< setw(TITLE_OUTPUT_WIDTH) << "  TITLE" << endl;
}

//-----------------------------------------------------------------------------
// setData
// build data from file

bool Periodical::setData(istream & infile){
    amount = 1;
	infile.get();   
	getline(infile, title, ',');
	infile >> this->month;
	infile.get();   
	infile >> this->year;
    infile.get();
	return true;
}

//-----------------------------------------------------------------------------
// setDataPartial
// build partial data from file

bool Periodical::setDataPartial(istream & infile){
    char temp;      // check to see if hard copy
    infile >> temp;
    
    // don't set data if not hard copy
    if (temp != 'H') {
        string k;
        getline(infile, k);
        return false;
    }
    
    infile >> year;
    infile >> month;

	infile.get();
	getline(infile, title, ',');
	infile.get();
    
	return true;
}

//-----------------------------------------------------------------------------
// hash
// gets hash of the object

int Periodical::hash() const{
	return 'p' - 'a';
}

//-----------------------------------------------------------------------------
// create
// returns clone of periodical for use in factory

Periodical* Periodical::create() {
    return new Periodical();
}

//-----------------------------------------------------------------------------
// operator<

bool Periodical::operator<(const NodeData & right) const{
	const Periodical& book = static_cast<const Periodical&>(right);
	if(this->month < book.month) return true;
	if(this->year < book.year) return true;
	if(this->title < book.title) return true;
	return false;
}

//-----------------------------------------------------------------------------
// operator<=

bool Periodical::operator<=(const NodeData & right) const{
	const Periodical& book = static_cast<const Periodical&>(right);
	if(this->month == book.month && this->year == book.year
	&& this->title == book.title) return true;
	if(this->month < book.month) return true;
	if(this->year < book.year) return true;
	return false;
}

//-----------------------------------------------------------------------------
// operator>

bool Periodical::operator>(const NodeData & right) const{
	const Periodical& book = static_cast<const Periodical&>(right);
	if(this->month > book.month) return true;
	if(this->year > book.year) return true;
	if(this->title > book.title) return true;
	return false;
}

//-----------------------------------------------------------------------------
// operator>=

bool Periodical::operator>=(const NodeData & right) const{

	const Periodical& book = static_cast<const Periodical&>(right);
	if(this->month == book.month && this->year == book.year
	&& this->title == book.title) return true;
	if(this->month > book.month) return true;
	if(this->year > book.year) return true;
	return false;
}

//-----------------------------------------------------------------------------
// operator==

bool Periodical::operator==(const NodeData & right) const{
	const Periodical& book = static_cast<const Periodical&>(right);
	if(this->month == book.month && this->year == book.year
		&& this->title == book.title) return true;
    return false;
}

//-----------------------------------------------------------------------------
// operator!=

bool Periodical::operator!=(const NodeData & right) const{
	return !(*this==right);
}

