//
//  return.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef RETURN_H
#define RETURN_H

#include <iostream>
#include "command.h"
#include "userfactory.h"
#include "itemfactory.h"

using namespace std;

class Return : public Command {

public:
    Return();
    virtual ~Return();

      
    virtual int hash() const;
    virtual Command* create();
    virtual bool execute(Library &);
    
    virtual bool setData(istream &);

	virtual void print() const;

	Item* getItem() const;
    
private:
    User* user;
    Item* item;

};

#endif


