//
//  user.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef USER_H
#define USER_H

#include <iostream>
#include "nodedata.h"

using namespace std;

class User : public NodeData {

public:
    User();
    ~User();
    
    User* create();
    bool setData(istream &);
    
    
    virtual bool operator==(const NodeData &) const;
    
private:
    string firstName;
    string lastName;
    int number;

};

#endif


