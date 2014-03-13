#ifndef NODEDATA_H
#define NODEDATA_H

#include <iostream>
#include <iomanip>
using namespace std;

// simple abstract class to allow tree to consist
// of multiple classes

class NodeData {

	friend ostream& operator<<(ostream &, NodeData &);

public:

	virtual ~NodeData() { }

    virtual bool setData(istream &) = 0;
    virtual bool setDataPartial(istream &) = 0;

    virtual void printHeader() const = 0;

	virtual void print(bool) const = 0;


    virtual bool operator==(const NodeData &) const = 0;
    virtual bool operator!=(const NodeData &) const = 0;
    virtual bool operator<(const NodeData &) const = 0;
    virtual bool operator>(const NodeData &) const = 0;
    virtual bool operator<=(const NodeData &) const = 0;
    virtual bool operator>=(const NodeData &) const = 0;
    

};

#endif


