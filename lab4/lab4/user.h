//
//  user.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include "nodedata.h"
#include "command.h"

using namespace std;

class User : public NodeData {

public:
    User();
    virtual ~User();
    
	virtual void print() const;

    User* create();
    virtual bool setData(istream &);
    virtual bool setDataCommand(istream &);

    void addHistory(Command*);
	vector<Command*> getHistory();
    
    virtual bool operator==(const NodeData &) const;
    virtual bool operator!=(const NodeData &) const;
    virtual bool operator<(const NodeData &) const;
    virtual bool operator>(const NodeData &) const;
    virtual bool operator<=(const NodeData &) const;
    virtual bool operator>=(const NodeData &) const;
    
private:
    string firstName;
    string lastName;
    int idNumber;
    vector<Command*> history;

};

#endif


