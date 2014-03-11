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
    for (int i = 0; i < 26; i++) {
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
    
    if (i >= 0 && i <= 26)
        return objFactory[i] != NULL;
    else
        return false;
}

