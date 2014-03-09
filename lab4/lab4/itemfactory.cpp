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
    for (int i = 0; i < 26; i++) {
        objFactory[i] = NULL;
    }
    objFactory[24] = new YouthBook();
    objFactory[15] = new Periodical();
    objFactory[5] = new FictionBook();
}

//-----------------------------------------------------------------------------
// destructor

ItemFactory::~ItemFactory() {
    for (int i = 0; i < 26; i++) {
        delete objFactory[i];
        objFactory[i] = NULL;
    }
}

//-----------------------------------------------------------------------------
// create

Item* ItemFactory::createIt(char c) {
    tolower(c);
    int i = c - 'a';
    return objFactory[i]->create();
}