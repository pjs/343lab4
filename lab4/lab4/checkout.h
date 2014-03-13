//
//  checkout.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class Checkout
//
// Checkout is a command. A Checkout command has a user and item to checkout
// of the library. A checkout command checks the item out to the user. 
// 
//
// Assumptions:
// - a checkout only checks out one item at a time
// 
//-----------------------------------------------------------------------------

#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <iostream>
#include "command.h"
#include "userfactory.h"
#include "itemfactory.h"

using namespace std;

class Checkout : public Command {

public:
    Checkout();           // constructor
    virtual ~Checkout();  // destructor
      
    virtual int hash() const;        // gets hash of command
    virtual Command* create();       // clones the command (for factory)
    virtual bool execute(Library &); // runs the command on a library
    virtual bool setData(istream &); // builds the command from a data file
	virtual void print() const;      // displays the command to cout
	Item* getItem() const;           // returns the item inside the command
    
private:
    User* user;   // user inside the command
    Item* item;   // item inside the command
    
    bool userPtrElsewhere;  // user ptr is pointing to an obj elsewhere
    bool itemPtrElsewhere;  // item ptr is pointing to an obj elsewhere

};

#endif




