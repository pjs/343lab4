//
//  user.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class User
//
//
// A user is a Nodedata. Users have first and last names and a unique ID
// number. A user also has a history of commands ran using their ID number
//
// Assumptions:
// - user input files are formated properly
//-----------------------------------------------------------------------------

#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>
#include "nodedata.h"
#include "command.h"

using namespace std;

class User : public NodeData {

public:
    User();            // constructor
    virtual ~User();   // destructor
    
    virtual void printHeader() const;  // display header info
	virtual void print(bool) const;    // display user info

    User* create();    // return clone (for factory)
    
    virtual bool setData(istream &);         // set user data from file
    virtual bool setDataPartial(istream &);  // set partial data from file

	vector<Command*>& getHistory();  // return users history
    
    // equality operators
    virtual bool operator==(const NodeData &) const;
    virtual bool operator!=(const NodeData &) const;
    virtual bool operator<(const NodeData &) const;
    virtual bool operator>(const NodeData &) const;
    virtual bool operator<=(const NodeData &) const;
    virtual bool operator>=(const NodeData &) const;
    
private:
    string firstName;   // first name of user
    string lastName;    // last name of user
    int idNumber;       // user's ID number
    
    vector<Command*> history; // user's history

};

#endif



