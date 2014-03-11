//
// book.cpp
//
// Paul Simpson
// Trevor Olson
//

#include "book.h"

Book::Book(string author, string title, int year) :
        Item() {
    
	this->author = author;
	this->title = title;
	this->year = year;
}

