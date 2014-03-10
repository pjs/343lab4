//
// displaylibrary.cpp
//
// Paul Simpson
// Trevor Olson
//

#include "displaylibrary.h"

//-----------------------------------------------------------------------------
// constructor

DisplayLibrary::DisplayLibrary() {
    
}


//-----------------------------------------------------------------------------
// destructor

DisplayLibrary::~DisplayLibrary() {
    
}

//-----------------------------------------------------------------------------
// hash

int DisplayLibrary::hash() const {
    return 'd' - 'a';
}

//-----------------------------------------------------------------------------
// create

Command* DisplayLibrary::create() {
    return new DisplayLibrary();
}

//-----------------------------------------------------------------------------
// execute

void DisplayLibrary::execute(Library library) {
    library.displayLibrary();
}

//-----------------------------------------------------------------------------
// setData

bool DisplayLibrary::setData(istream &data) {
    
    return true;
}


