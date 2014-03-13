//
//  displayhistory.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class DisplayHistory
//
// A command to display the history of an user, to the console
//
//
// Assumptions:
// - displays the history for only one user
// 
//-----------------------------------------------------------------------------

#ifndef DISPLAYHISTORY_H
#define DISPLAYHISTORY_H

#include <iostream>
#include "command.h"

using namespace std;

class DisplayHistory : public Command {

public:
    DisplayHistory();           // constructor
    virtual ~DisplayHistory();  // destructor

    virtual int hash() const;         // returns hash of the command
    virtual Command* create();        // returns clone (for factory)
    virtual bool execute(Library &);  // runs command on library
    virtual bool setData(istream &);  // sets command data from file
	virtual void print() const;       // displays the command
    
private:
    User* user;  // related user history to display

};

#endif




