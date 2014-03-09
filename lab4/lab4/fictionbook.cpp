//
// fictionBook.cpp
//
// Paul Simpson
// Trevor Olson
//

#include "fictionBook.h"

FictionBook::FictionBook(string author, string title, int year) : 
	Book(author, title, year){}

FictionBook::~FictionBook() {
    
}

bool FictionBook::setData(istream & infile){
	infile.get();   
	getline(infile, author, ',');
	infile.get();   
	getline(infile, title, ',');
	infile.get();   
	infile >> this->year;
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
	if(this->author == book.author) return true;
	if(this->title == book.title) return true;
	return false; 
}
bool FictionBook::operator!=(const NodeData & right) const{
	return !(*this==right);
}