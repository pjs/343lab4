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