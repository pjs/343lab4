//
//  displaylibrary.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class DisplayLibrary
//
//
// A command to display the library, to the console. 
//
//
// Assumptions:
// - displays the containts of only one library
//
//-----------------------------------------------------------------------------

#ifndef DISPLAYLIBRARY_H
#define DISPLAYLIBRARY_H

#include <iostream>
#include "command.h"

using namespace std;

class DisplayLibrary : public Command {

public:
    DisplayLibrary();          // constructor
    virtual ~DisplayLibrary(); // destructor

      
    virtual int hash() const;         // returns hash of command
    virtual Command* create();        // returns clone (for factory)
    virtual bool execute(Library &);  // runs command on library
    virtual bool setData(istream &);  // builds data from file
	virtual void print() const;       // displays the command
    
private:
    static const int FACTORY_SIZE = 26;  // size of objects in factory

};

#endif


