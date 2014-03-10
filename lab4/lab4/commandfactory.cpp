//
//  commandfactory.cpp
//
//  Paul Simpson
//  Trevor Olson
//


#include "commandfactory.h"
#include "displaylibrary.h"

//-----------------------------------------------------------------------------
// constructor

CommandFactory::CommandFactory() {
    for (int i = 0; i < 26; i++) {
        objFactory[i] = NULL;
    }
    objFactory[3] = new DisplayLibrary();
}

//-----------------------------------------------------------------------------
// destructor

CommandFactory::~CommandFactory() {
    for (int i = 0; i < 26; i++) {
        delete objFactory[i];
        objFactory[i] = NULL;
    }
}

//-----------------------------------------------------------------------------
// create

Command* CommandFactory::createIt(int c) {
    c = tolower(c);
    int i = c - 'a';
    
    return objFactory[i]->create();
}

//-----------------------------------------------------------------------------
// isValid

bool CommandFactory::isValid(int c) const {
    c = tolower(c);
    int i = c - 'a';
    
    return objFactory[i] != NULL;
}