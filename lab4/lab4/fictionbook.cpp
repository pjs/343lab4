//
// fictionbook.cpp
//
// Paul Simpson
// Trevor Olson
//

#include "fictionbook.h"

//-----------------------------------------------------------------------------
// constructor

FictionBook::FictionBook(string author, string title, int year) :
    Book(author, title, year) {
    
}

//-----------------------------------------------------------------------------
// destructor

FictionBook::~FictionBook() {
    
}

//-----------------------------------------------------------------------------
// print
// displays formatted book information, doesn't display amount if parameter
// is set to true

void FictionBook::print(bool partial) const {
	if(!partial) {
		cout << " " << left << setw(AVAIL_OUTPUT_WIDTH) << amount;
	}
	cout  << setw(AUTHOR_OUTPUT_WIDTH) << author.substr(0,AUTHOR_OUTPUT_WIDTH) 
		<< " " << setw(TITLE_OUTPUT_WIDTH) << title.substr(0,TITLE_OUTPUT_WIDTH)
		<< " " << setw(YEAR_OUTPUT_WIDTH) << year << endl;
}

//-----------------------------------------------------------------------------
// printHeader
// displays header information for the book

void FictionBook::printHeader() const {
	cout << "Fiction:" << endl << left << setw(AVAIL_OUTPUT_WIDTH) << "AVAIL  " << 
		setw(AUTHOR_OUTPUT_WIDTH) << "AUTHOR" << setw(TITLE_OUTPUT_WIDTH) 
		<< " TITLE" << setw(YEAR_OUTPUT_WIDTH) << "  YEAR" << endl;
}

//-----------------------------------------------------------------------------
// setData
// build book data from file

bool FictionBook::setData(istream & infile){
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
// build partial data about the book from a file

bool FictionBook::setDataPartial(istream & infile){
    char temp;      // temp char to check for hardcopy
    infile >> temp;
    
    // make sure it is a hard copy
    if (temp != 'H') {
        string k;
        getline(infile, k);
        return false;
    }
    
    // get rest of the information
	infile.get();
	getline(infile, author, ',');
	infile.get();
	getline(infile, title, ',');
	infile.get();
    
	return true;
}

//-----------------------------------------------------------------------------
// hash
// gets a hash for the book

int FictionBook::hash() const{
	return 'f' - 'a';
}

//-----------------------------------------------------------------------------
// create
// returns new clone for use in the factory

FictionBook* FictionBook::create() {
    return new FictionBook();
}

//-----------------------------------------------------------------------------
// operator<

bool FictionBook::operator<(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author < book.author) return true;
	if(this->title < book.title) return true;
	if(this->year < book.year) return true;
	return false; 
}

//-----------------------------------------------------------------------------
// constructor>

bool FictionBook::operator>(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author > book.author) return true;
	if(this->title > book.title) return true;
	if(this->year > book.year) return true;
	return false; 
}

//-----------------------------------------------------------------------------
// constructor<=

bool FictionBook::operator<=(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author <= book.author) return true;
	if(this->title <= book.title) return true;
	return false; 
}

//-----------------------------------------------------------------------------
// constructor>=

bool FictionBook::operator>=(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author >= book.author) return true;
	if(this->title >= book.title) return true;
	return false; 
}

//-----------------------------------------------------------------------------
// constructor==

bool FictionBook::operator==(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author == book.author &&this->title == book.title ) return true;
	return false; 
}

//-----------------------------------------------------------------------------
// constructor!=

bool FictionBook::operator!=(const NodeData & right) const{
	return !(*this==right);
}

