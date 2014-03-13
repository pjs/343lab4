//
//  youthbook.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class YouthBook
//
// A book designed for youth readers
//
// Assumptions:
// - all youth books are hard copies
//
//-----------------------------------------------------------------------------

#ifndef YOUTHBOOK_H
#define YOUTHBOOK_H

#include "book.h"

using namespace std;

class YouthBook : public Book {
    
public:
    YouthBook(string = "", string = "", int = 0);  // constructor
    virtual ~YouthBook();   // destructor

    virtual void printHeader() const;        // print object header
	virtual void print(bool) const;          // print object

	virtual bool setData(istream &);         // set data from file
    virtual bool setDataPartial(istream &);  // set partial data

	virtual int hash() const;     // get hash of object
    virtual YouthBook* create();  // return clone for factory

    // equality operators
    virtual bool operator<(const NodeData &) const;
    virtual bool operator>(const NodeData &) const;
    virtual bool operator<=(const NodeData &) const;
    virtual bool operator>=(const NodeData &) const;
	virtual bool operator==(const NodeData &) const;
	virtual bool operator!=(const NodeData &) const;
};

#endif


