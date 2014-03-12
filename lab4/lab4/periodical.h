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

const static int MO_OUTPUT_WIDTH = 3; 

class Periodical : public Item {

 
protected:
    int month;
    int year;
    
public:
    Periodical(string = "", int = 5, int = 0, int = 0);
	virtual ~Periodical();
    
	virtual void print(bool) const;

	virtual bool setData(istream &);
    virtual bool setDataPartial(istream &);

	virtual int hash() const;
    virtual Periodical* create();

    virtual bool operator<(const NodeData &) const;
    virtual bool operator>(const NodeData &) const;
    virtual bool operator<=(const NodeData &) const;
    virtual bool operator>=(const NodeData &) const;

	
	virtual bool operator==(const NodeData &) const;
	virtual bool operator!=(const NodeData &) const;

};

#endif


