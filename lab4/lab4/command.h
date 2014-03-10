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

class Command : public Hashable {
    friend ostream& operator<<(ostream &, Command &);

public:
    Command();
    virtual ~Command();
    virtual Command* create() = 0;
    virtual bool execute(Library &) = 0;
    virtual bool setData(istream &) = 0;
	virtual void print() const = 0;
};

#endif
