//
//  command.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef COMMAND_H
#define COMMAND_H

#include "hashable.h"
#include "library.h"

using namespace std;

//-----------------------------------------------------------------------------
// class Command
//
// A command is a hashable class. A command executes a certain action on a 
// library object. This is an abstract class. 
//
// Assumptions:
// - 
//-----------------------------------------------------------------------------

class Command : public Hashable {
    friend ostream& operator<<(ostream &, Command &);

public:
    Command();								//constructor
    virtual ~Command();					    //destructor
    virtual Command* create() = 0;			//create a empty command object
    virtual bool execute(Library &) = 0;	//executes the command
    virtual bool setData(istream &) = 0;	//sets the data in command
	virtual void print() const = 0;			//prints command to console
};

#endif


