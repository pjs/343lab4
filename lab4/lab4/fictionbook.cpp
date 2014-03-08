//
// fictionBook.cpp
//
// Paul Simpson
// Trevor Olson
//

#include "fictionBook.h"

FictionBook::FictionBook(string author, string title, int year) : 
	Book(author, title, year){}

int FictionBook::hash() const{
	return 'f' - 'a';
}

bool FictionBook::operator<(const Item & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author < book.author) return true;
	if(this->title < book.title) return true;
	return false; 
}
bool FictionBook::operator>(const Item & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author > book.author) return true;
	if(this->title > book.title) return true;
	return false; 
}
bool FictionBook::operator<=(const Item & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author <= book.author) return true;
	if(this->title <= book.title) return true;
	return false; 
}
bool FictionBook::operator>=(const Item & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author >= book.author) return true;
	if(this->title >= book.title) return true;
	return false; 
}

bool FictionBook::operator==(const Item & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author == book.author) return true;
	if(this->title == book.title) return true;
	return false; 
}