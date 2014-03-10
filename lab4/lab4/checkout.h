//
//  checkout.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <iostream>
#include "command.h"
#include "userfactory.h"
#include "itemfactory.h"

using namespace std;

class Checkout : public Command {

public:
    Checkout();
    virtual ~Checkout();

      
    virtual int hash() const;
    virtual Command* create();
    virtual bool execute(Library &);
    
    virtual bool setData(istream &);
    
private:
    User* user;
    Item* item;

};

#endif


