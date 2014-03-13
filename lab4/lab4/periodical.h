//
//  periodical.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class Periodical
//
//
// A periodical is a item that has a month and year associated to it
//
// Assumptions:
// - all periodicals have months and years
// - all periodicals are hard copies
//-----------------------------------------------------------------------------

#ifndef PERIODICAL_H
#define PERIODICAL_H

#include "item.h"

using namespace std;

const static int MO_OUTPUT_WIDTH = 3;  // month width

class Periodical : public Item {
    
protected:
    int month;  // month of publication
    int year;   // year of publiciation
    
public:
    Periodical(string = "", int = 0, int = 0, int = 0);  // constructor
	virtual ~Periodical();                               // destructor

    virtual void printHeader() const;    // print object header
	virtual void print(bool) const;      // print item info

	virtual bool setData(istream &);        // set data from file
    virtual bool setDataPartial(istream &); // set partial data

	virtual int hash() const;     // hash of item
    virtual Periodical* create(); // return clone (for factory)

    // equality operators
    virtual bool operator<(const NodeData &) const;
    virtual bool operator>(const NodeData &) const;
	virtual bool operator==(const NodeData &) const;
	virtual bool operator!=(const NodeData &) const;

};

#endif


