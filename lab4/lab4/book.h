//
//  book.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class Book
//
// Abstract class. A book is an item that contains both a year and an author.
//
// Assumptions:
// - a book only has one author
//-----------------------------------------------------------------------------

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "item.h"

using namespace std;

const static int AUTHOR_OUTPUT_WIDTH = 20;

class Book : public Item {
    
protected:
    int year;	    // year book is published
	string author;  // author of the book

public:
    Book(string = "", string = "", int = 0); // constructs a book

};

#endif




