//
//  periodical.cpp
//
//  Paul Simpson
//  Trevor Olson
//


#include "periodical.h"


Periodical::Periodical(string title, int amount, int month, int year)
	:Item(){
	
	this->month = month;
	this->year = year;
}

Periodical::~Periodical(){
	
}

void Periodical::print(bool partial)const{
	if(!partial){
		cout << " " << setw(AVAIL_OUTPUT_WIDTH) << amount; 
	}
	cout << setw(YEAR_OUTPUT_WIDTH) << year << " " << setw(MO_OUTPUT_WIDTH) << 
		month << " " << left << setw(TITLE_OUTPUT_WIDTH) << 
		title.substr(0,TITLE_OUTPUT_WIDTH)  << endl;
}

void Periodical::printHeader() const {
	cout << "Periodicals:" << endl << setw(AVAIL_OUTPUT_WIDTH) << "AVAIL" << 
		setw(YEAR_OUTPUT_WIDTH) << " YEAR" << setw(MO_OUTPUT_WIDTH) << " MO"
		<< setw(TITLE_OUTPUT_WIDTH) << "  TITLE" << endl;
}

bool Periodical::setData(istream & infile){
    amount = AMOUNT;
	infile.get();   
	getline(infile, title, ',');
	infile >> this->month;
	infile.get();   
	infile >> this->year;
    infile.get();
	return true;
}

bool Periodical::setDataPartial(istream & infile){
    char temp;
    infile >> temp;
    
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

