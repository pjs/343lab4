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

bool DisplayLibrary::execute(Library &library) {
    for (int i = 0; i < 26; i++) {
        if (!library.getItems(i).isEmpty()) {
            library.getItems(i).getRoot()->printHeader();
            
            cout << library.getItems(i);
        }
    }
    
    return false;
}

//-----------------------------------------------------------------------------
// setData

bool DisplayLibrary::setData(istream &data) {
    
    return true;
}

//-----------------------------------------------------------------------------
// print
void DisplayLibrary::print()const{
	cout << "diplay library command";
}



