//
//  fictionbook.cpp
//
//  Paul Simpson
//  Trevor Olson
//

#include "fictionBook.h"

FictionBook::FictionBook(string author, string title, int year) : 
	Book(author, title, year){}

int FictionBook::hash() const{
	return 'f' - 'a';
}

