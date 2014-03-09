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

class FictionBook : public Book {
    
protected:

    
public:
    FictionBook(string = "", string = "", int = 0);
    
	virtual bool setData(istream &);

	virtual int hash() const;

    virtual bool operator<(const NodeData &) const;
    virtual bool operator>(const NodeData &) const;
    virtual bool operator<=(const NodeData &) const;
    virtual bool operator>=(const NodeData &) const;

	
	virtual bool operator==(const NodeData &) const;
	virtual bool operator!=(const NodeData &) const;
};

#endif
