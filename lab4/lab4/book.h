//
//  book.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "item.h"

using namespace std;

class Book : public Item {
    
protected:

    int year;
	string author;


public:
    Book(string = "", string = "", int = 0);

      
    virtual int hash() const = 0;

};

#endif




