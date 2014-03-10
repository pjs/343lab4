//
//  manager.cpp
//
//  Paul Simpson
//  Trevor Olson
//


#include "manager.h"
#include "user.h"
#include <fstream>

using namespace std;

//-----------------------------------------------------------------------------
// constructor

Manager::Manager() {
    
}

//-----------------------------------------------------------------------------
// destructor

Manager::~Manager() {
    
}

//-----------------------------------------------------------------------------
// run

void Manager::run() {
    ifstream userFile("data4patrons.txt");
    //istream& iUserFile = userFile;
    
    buildUsers(userFile);

	ifstream itemFile("data4books.txt");

	buildItems(itemFile);

	library.displayLibrary();
    cout << "test" << endl;
  
}

//-----------------------------------------------------------------------------
// buildUsers

void Manager::buildUsers(istream& infile) {
    
    User* ptr = NULL;       // temp pointer to hold new User
    bool successfulRead;    // read good data
    for (;;) {
        ptr = userFact.createIt(0);
        successfulRead = ptr->setData(infile);
        if (infile.eof()) {
            delete ptr;
            break;
        }
        
        if (successfulRead) {
            
            // add user to library
            library.addUser(ptr);
        }
        else {
            delete ptr;
        }
    }
}

//-----------------------------------------------------------------------------
// buildItems

void Manager::buildItems(istream& infile) {
    
    Item* ptr = NULL;       // temp pointer to hold new User
    char temp;
    bool successfulRead;    // read good data
    for (;;) {
        infile >> temp;
        ptr = itemFact.createIt(temp);
        successfulRead = ptr->setData(infile);
        if (infile.eof()) {
            delete ptr;
            break;
        }
        
        if (successfulRead) {
            
            // add user to library
            //library.addUser(ptr);
        }
        else {
            delete ptr;
        }
    }
}