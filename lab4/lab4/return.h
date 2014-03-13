//
//  return.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class Return
//
// A return is a command that returns the item to the library, that is 
// checked out by the user
//
// Assumptions:
// - only one return happens per return command
//-----------------------------------------------------------------------------

#ifndef RETURN_H
#define RETURN_H

#include <iostream>
#include "command.h"
#include "userfactory.h"
#include "itemfactory.h"

using namespace std;

class Return : public Command {

public:
    Return();           // destructor
    virtual ~Return();  // constructor

    virtual int hash() const;        // returns hash of command
    virtual Command* create();       // returns a clone (for factory)
    virtual bool execute(Library &); // runs the return on a library
    virtual bool setData(istream &); // sets return data from file
	virtual void print() const;      // prints the return command
	Item* getItem() const;           // returns the item inside the return
    
private:
    User* user;    // user belonging to the return
    Item* item;    // item belonging to the return
    
    bool userPtrElsewhere;  // keeps track of user being deleted already
    bool itemPtrElsewhere;  // keeps track of item being deleted already

};

#endif


