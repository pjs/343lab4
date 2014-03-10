//
//  youthbook.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef YOUTHBOOK_H
#define YOUTHBOOK_H

#include "book.h"

using namespace std;

class YouthBook : public Book {

    
protected:

    
public:
    YouthBook(string = "", string = "", int = 0);
    virtual ~YouthBook();

	virtual void print() const;
    
	virtual bool setData(istream &);
    virtual bool setDataCommand(istream &);

	virtual int hash() const;
    virtual YouthBook* create();

    virtual bool operator<(const NodeData &) const;
    virtual bool operator>(const NodeData &) const;
    virtual bool operator<=(const NodeData &) const;
    virtual bool operator>=(const NodeData &) const;

	
	virtual bool operator==(const NodeData &) const;
	virtual bool operator!=(const NodeData &) const;
};

#endif
