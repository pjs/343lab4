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
    
    int item;
	cout << "Fiction:" << endl << setw(5) << "AVAIL" << setw(20) << "AUTHOR"
    << setw(30) << "TITLE" << setw(4) << "YEAR" << endl;
	item = 'f' - 'a';
	cout << library.getItems(item);
    
	cout << "Youth:" << endl << setw(5) << "AVAIL" << setw(20)
    << "AUTHOR" << setw(30) << "TITILE" << setw(4) << "YEAR" << endl;
	item = 'y' - 'a';
	cout << library.getItems(item);
    
	cout << "Periodicals:" << endl << setw(5) << "AVAIL" << setw(4)
    << "YEAR" << setw(2) << "MO" << setw(30) << "TITLE" << endl;
	item = 'p' - 'a';
	cout << library.getItems(item);
    
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



