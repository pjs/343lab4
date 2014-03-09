//
//  periodical.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef PERIODICAL_H
#define PERIODICAL_H

#include "item.h"

using namespace std;

class Periodical : public Item {
    
protected:
    int month;
    int year;
    
public:
    Periodical(string = "", int = 0, int = 0, int = 0);
    
    
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
