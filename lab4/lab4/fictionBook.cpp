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

bool FictionBook::operator<(const FictionBook & right) const{
	if(this->author < right.author) return true;
	if(this->title < right.title) return true;
	return false; 
}

