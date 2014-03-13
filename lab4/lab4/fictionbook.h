//
//  fictionbook.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class FictionBook
//
// FictionBook is a book, that is fictional.
//
// Assumptions:
// - all fiction books are hard copies
//
//-----------------------------------------------------------------------------

#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

#include <iostream>
#include "book.h"

using namespace std;

class FictionBook : public Book {
    
public:
    FictionBook(string = "", string = "", int = 0);  // constructor
    virtual ~FictionBook();                          // destructor

    virtual void printHeader() const;  // display header
	virtual void print(bool) const;    // display object

	virtual bool setData(istream &);         // set object data
    virtual bool setDataPartial(istream &);  // set partial data

	virtual int hash() const;       // get book hash
    virtual FictionBook* create();  // return new object (for factory)

    // equality operators
    virtual bool operator<(const NodeData &) const;
    virtual bool operator>(const NodeData &) const;
    virtual bool operator<=(const NodeData &) const;
    virtual bool operator>=(const NodeData &) const;
	virtual bool operator==(const NodeData &) const;
	virtual bool operator!=(const NodeData &) const;
};

#endif


