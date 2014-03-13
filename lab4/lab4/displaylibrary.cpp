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
// returns hash of the command

int DisplayLibrary::hash() const {
    return 'd' - 'a';
}

//-----------------------------------------------------------------------------
// create
// returns clone of the command (for use in the factory)

Command* DisplayLibrary::create() {
    return new DisplayLibrary();
}

//-----------------------------------------------------------------------------
// execute
// runs the command on  the library

bool DisplayLibrary::execute(Library &library) {
    
    // loop through each object type in the library
    // and display its contents if it exists
    for (int i = 0; i < FACTORY_SIZE; i++) {
        if (!library.getItems(i).isEmpty()) {
            library.getItems(i).getRoot()->printHeader();
            
            cout << library.getItems(i);
        }
    }
    
    return false;
}

//-----------------------------------------------------------------------------
// setData
// builds data from file

bool DisplayLibrary::setData(istream &data) {
    
    // nothing to set because command
    // doesn't have any specific data (just 'D')
    
    return true;
}

//-----------------------------------------------------------------------------
// print
// displays the command

void DisplayLibrary::print() const {
	cout << "diplay library command";
}



