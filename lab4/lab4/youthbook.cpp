//
//  youthbook.cpp
//
//  Paul Simpson
//  Trevor Olson
//

#include "youthBook.h"

YouthBook::YouthBook(string author, string title, int year)
	:Book(author, title, year){}

int YouthBook::hash() const{
	return 'y' - 'a';
}