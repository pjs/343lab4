//
//  checkout.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class Checkout
//
//
//
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
    
    bool userPtrElsewhere;  // if deleting of user has already been done
    bool itemPtrElsewhere;  // if deleting of item has already been done

};

#endif




