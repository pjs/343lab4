//
//  nodedata.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class NodeData
//
// Simple abstract class to allow tree to consist of multiple classes
//-----------------------------------------------------------------------------

#ifndef NODEDATA_H
#define NODEDATA_H

#include <iostream>
#include <iomanip>

using namespace std;

class NodeData {

	friend ostream& operator<<(ostream &, NodeData &);

public:
	virtual ~NodeData();   // destructor
    
    virtual bool setData(istream &) = 0;        // build data from file
    virtual bool setDataPartial(istream &) = 0; // build partial data
    virtual void printHeader() const = 0;       // print header for object
	virtual void print(bool) const = 0;         // print object

    // pure virtual equality operators
    virtual bool operator==(const NodeData &) const = 0;
    virtual bool operator!=(const NodeData &) const = 0;
    virtual bool operator<(const NodeData &) const = 0;
    virtual bool operator>(const NodeData &) const = 0;

};

#endif


