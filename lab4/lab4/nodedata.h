#ifndef NODEDATA_H
#define NODEDATA_H

#include <iostream>
#include <iomanip>
using namespace std;

// simple class containing one string to use for testing
// not necessary to comment further

class NodeData {

	friend ostream& operator<<(ostream &, NodeData &);

public:

	virtual ~NodeData() { }

    virtual bool setData(istream &) = 0;
    virtual bool setDataCommand(istream &) = 0;

	virtual void print() const = 0;
    virtual void printHeader() const = 0;

    virtual bool operator==(const NodeData &) const = 0;
    virtual bool operator!=(const NodeData &) const = 0;
    virtual bool operator<(const NodeData &) const = 0;
    virtual bool operator>(const NodeData &) const = 0;
    virtual bool operator<=(const NodeData &) const = 0;
    virtual bool operator>=(const NodeData &) const = 0;
    

};

#endif


