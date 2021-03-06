//
//  itemfactory.cpp
//
//  Paul Simpson
//  Trevor Olson
//


#include "itemfactory.h"
#include "youthbook.h"
#include "periodical.h"
#include "fictionbook.h"

//-----------------------------------------------------------------------------
// constructor

ItemFactory::ItemFactory() {
    for (int i = 0; i < FACTORY_SIZE; i++) {
        objFactory[i] = NULL;
    }
    objFactory[24] = new YouthBook();
    objFactory[15] = new Periodical();
    objFactory[5] = new FictionBook();
}

//-----------------------------------------------------------------------------
// destructor

ItemFactory::~ItemFactory() {
    for (int i = 0; i < FACTORY_SIZE; i++) {
        delete objFactory[i];
        objFactory[i] = NULL;
    }
}

//-----------------------------------------------------------------------------
// create
// returns clone of requested item

Item* ItemFactory::createIt(int c) {
    c = tolower(c);
    int i = c - 'a';
    
    return objFactory[i]->create();
}

//-----------------------------------------------------------------------------
// isValid
// checks to see if item can be cloned

bool ItemFactory::isValid(int c) const {
    c = tolower(c);
    int i = c - 'a';
    
    if (i >= 0 && i <= FACTORY_SIZE)
        return objFactory[i] != NULL;
    else
        return false;
}

