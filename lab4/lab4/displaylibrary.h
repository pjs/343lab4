//
//  displaylibrary.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef DISPLAYLIBRARY_H
#define DISPLAYLIBRARY_H

#include <iostream>
#include "command.h"

using namespace std;

class DisplayLibrary : public Command {

public:
    DisplayLibrary();
    virtual ~DisplayLibrary();

      
    virtual int hash() const;
    virtual Command* create();
    virtual bool execute(Library &);
    
    virtual bool setData(istream &);
	
	virtual void print() const;
    
private:
    static const int FACTORY_SIZE = 26;

};

#endif


