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
    virtual void execute(Library);
    
    virtual bool setData(istream &);

};

#endif


