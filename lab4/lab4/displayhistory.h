//
//  displayhistory.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef DISPLAYHISTORY_H
#define DISPLAYHISTORY_H

#include <iostream>
#include "command.h"

using namespace std;

class DisplayHistory : public Command {

public:
    DisplayHistory();
    virtual ~DisplayHistory();

      
    virtual int hash() const;
    virtual Command* create();
    virtual bool execute(Library &);
    
    virtual bool setData(istream &);

	virtual void print() const;
private:
    User* user;

};

#endif


