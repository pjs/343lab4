//
//  fictionBook.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

#include <iostream>
#include "book.h"

using namespace std;

//-----------------------------------------------------------------------------
// class FictionBook 
//
// FictionBook is a book, that is fictional. 
//
// Assumptions:
// - all fiction books are hard copies
// 
//-----------------------------------------------------------------------------

class FictionBook : public Book {
    

protected:

    
public:
    FictionBook(string = "", string = "", int = 0);
    virtual ~FictionBook();

    virtual void printHeader() const;

	virtual void print(bool) const;

    
	virtual bool setData(istream &);
    virtual bool setDataPartial(istream &);

	virtual int hash() const;
    virtual FictionBook* create();

    virtual bool operator<(const NodeData &) const;
    virtual bool operator>(const NodeData &) const;
    virtual bool operator<=(const NodeData &) const;
    virtual bool operator>=(const NodeData &) const;

	
	virtual bool operator==(const NodeData &) const;
	virtual bool operator!=(const NodeData &) const;
};

#endif


