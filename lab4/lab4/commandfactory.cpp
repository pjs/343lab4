//
//  commandfactory.cpp
//
//  Paul Simpson
//  Trevor Olson
//

#include "commandfactory.h"
#include "displaylibrary.h"
#include "displayhistory.h"
#include "checkout.h"
#include "return.h"

//-----------------------------------------------------------------------------
// constructor

CommandFactory::CommandFactory() {
    
    // initialize the factory objects
    for (int i = 0; i < FACTORY_SIZE; i++) {
        objFactory[i] = NULL;
    }
    objFactory[2] = new Checkout();
    objFactory[3] = new DisplayLibrary();
    objFactory[7] = new DisplayHistory();
    objFactory[17] = new Return();
}

//-----------------------------------------------------------------------------
// destructor

CommandFactory::~CommandFactory() {
    for (int i = 0; i < FACTORY_SIZE; i++) {
        delete objFactory[i];
        objFactory[i] = NULL;
    }
}

//-----------------------------------------------------------------------------
// create
// returns the requested command object by calling a cloning function
// on the requested command

Command* CommandFactory::createIt(int c) {
    c = tolower(c);
    int i = c - 'a';
    
    return objFactory[i]->create();
}

//-----------------------------------------------------------------------------
// isValid
// checks to see if hash of object can be built by the factory

bool CommandFactory::isValid(int c) const {
    c = tolower(c);
    int i = c - 'a';
    
    if (i >= 0 && i <= FACTORY_SIZE)
        return objFactory[i] != NULL;
    else
        return false;
}

