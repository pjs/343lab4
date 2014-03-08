//
// book.cpp
//
// Paul Simpson
// Trevor Olson
//

#include "book.h"

Book::Book(string author, string title, int year):Item(title,5){
	this->author = author;
	this->year = year;
}

int Book::hash() const{
	return 'b' - 'a';
}
bool Book::operator<(const Book & right) const{
	return this->title < right.title;
}