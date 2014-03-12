//
// fictionBook.cpp
//
// Paul Simpson
// Trevor Olson
//

#include "fictionbook.h"


FictionBook::FictionBook(string author, string title, int year) : 
	Book(author, title, year){}

FictionBook::~FictionBook() {
    
}

void FictionBook::print() const{
	cout << setw(5) << amount << setw(20) << author << setw(30) << title << 
		setw(4) << year << endl;
}

void FictionBook::printHeader() const {
	cout << "Fiction:" << endl << setw(5) << "AVAIL" << setw(20) << "AUTHOR"
    << setw(30) << "TITLE" << setw(4) << "YEAR" << endl;
}

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

bool FictionBook::setDataCommand(istream & infile){
    char temp;
    infile >> temp;
    
    if (temp != 'H') {
        string k;
        getline(infile, k);
        return false;
    }
    
	infile.get();
	getline(infile, author, ',');
	infile.get();
	getline(infile, title, ',');
	infile.get();
    
	return true;
}

int FictionBook::hash() const{
	return 'f' - 'a';
}

FictionBook* FictionBook::create() {
    return new FictionBook();
}

bool FictionBook::operator<(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author < book.author) return true;
	if(this->title < book.title) return true;
	return false; 
}
bool FictionBook::operator>(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author > book.author) return true;
	if(this->title > book.title) return true;
	return false; 
}
bool FictionBook::operator<=(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author <= book.author) return true;
	if(this->title <= book.title) return true;
	return false; 
}
bool FictionBook::operator>=(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author >= book.author) return true;
	if(this->title >= book.title) return true;
	return false; 
}

bool FictionBook::operator==(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author == book.author &&this->title == book.title ) return true;
	return false; 
}
bool FictionBook::operator!=(const NodeData & right) const{
	return !(*this==right);
}

