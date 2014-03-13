//
//  youthbook.cpp
//
//  Paul Simpson
//  Trevor Olson
//

#include "youthbook.h"

//-----------------------------------------------------------------------------
// constructor

YouthBook::YouthBook(string author, string title, int year) :
    Book(author, title, year) {

}

//-----------------------------------------------------------------------------
// hash
// returns hash of the object

int YouthBook::hash() const{
	return 'y' - 'a';
}

//-----------------------------------------------------------------------------
// destructor

YouthBook::~YouthBook() {
    
}

//-----------------------------------------------------------------------------
// print
// print information on the object. if first parameter is true it will not
// display the amount

void YouthBook::print(bool partial) const {
	if(!partial){
		cout << " " << left << setw(AVAIL_OUTPUT_WIDTH) << amount;
	}
	cout << left << setw(AUTHOR_OUTPUT_WIDTH) <<
		author.substr(0,AUTHOR_OUTPUT_WIDTH) << " " << setw(TITLE_OUTPUT_WIDTH) 
		<< title.substr(0,TITLE_OUTPUT_WIDTH) << " " << setw(YEAR_OUTPUT_WIDTH) 
		<< year << endl;

}

//-----------------------------------------------------------------------------
// printHeader
// display header information for the book

void YouthBook::printHeader() const {
	cout << "Fiction:" << endl << setw(AVAIL_OUTPUT_WIDTH) << "AVAIL  " << 
		setw(AUTHOR_OUTPUT_WIDTH) << "AUTHOR" << setw(TITLE_OUTPUT_WIDTH) 
		<< " TITLE" << setw(YEAR_OUTPUT_WIDTH) << "  YEAR" << endl;
}

//-----------------------------------------------------------------------------
// setData
// builds data from file

bool YouthBook::setData(istream & infile){
    amount = AMOUNT;
	infile.get();
	getline(infile, author, ',');
	infile.get();
	getline(infile, title, ',');
	infile.get();
	infile >> this->year;
    infile.get();
	return true;
}

//-----------------------------------------------------------------------------
// setDataPartial
// builds partial data from file

bool YouthBook::setDataPartial(istream & infile){
    char temp;      // char to check for hard copy
    infile >> temp;
    
    // check to see if it is a hard copy
    if (temp != 'H') {
        string k;
        getline(infile, k);
        return false;
    }
    
    // get rest of the information
	infile.get();
	getline(infile, title, ',');
	infile.get();
	getline(infile, author, ',');
	infile.get();
    
	return true;
}

//-----------------------------------------------------------------------------
// create
// returns a clone of the book for use in the factory

YouthBook* YouthBook::create() {
    return new YouthBook();
}

//-----------------------------------------------------------------------------
// operator<

bool YouthBook::operator<(const NodeData & right ) const{
	const YouthBook& book = static_cast<const YouthBook&>(right);
	if(this->title < book.title) return true;
	if(this->author < book.author) return true;
	return false;
}

//-----------------------------------------------------------------------------
// operator<=

bool YouthBook::operator<=(const NodeData & right ) const{
	const YouthBook& book = static_cast<const YouthBook&>(right);
	if(this->title <= book.title) return true;
	if(this->author <= book.author) return true;
	return false;
}

//-----------------------------------------------------------------------------
// operator>

bool YouthBook::operator>(const NodeData & right ) const{
	const YouthBook& book = static_cast<const YouthBook&>(right);
	if(this->title > book.title) return true;
	if(this->author > book.author) return true;
	return false;
}

//-----------------------------------------------------------------------------
// operator>=

bool YouthBook::operator>=(const NodeData & right ) const{
	const YouthBook& book = static_cast<const YouthBook&>(right);
	if(this->title >= book.title) return true;
	if(this->author >= book.author) return true;
	return false;
}

//-----------------------------------------------------------------------------
// operator==

bool YouthBook::operator==(const NodeData & right ) const{
	const YouthBook& book = static_cast<const YouthBook&>(right);
	if(this->title == book.title && this->author == book.author) return true;
	return false;
}

//-----------------------------------------------------------------------------
// operator!=

bool YouthBook::operator!=(const NodeData & right ) const{
	return !(*this==right);
}

