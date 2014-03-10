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
    
    buildUsers(userFile);

	ifstream itemFile("data4books.txt");
    
	buildItems(itemFile);
    
    ifstream commandFile("data4commands.txt");
    
	buildCommands(commandFile);

	library.displayLibrary();
    library.displayUsers();
  
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
    
    Item* ptr = NULL;       // temp pointer to hold new Item
    char temp;
    bool successfulRead;    // read good data
    for (;;) {
        infile >> temp;
        if (itemFact.isValid(temp)) {
            ptr = itemFact.createIt(temp);
            
            successfulRead = ptr->setData(infile);
            if (infile.eof()) {
                delete ptr;
                break;
            }
            
            if (successfulRead) {
                
                // add item to library
                library.addItem(ptr);
            }
            else {
                delete ptr;
            }
        }
        else {
            if (infile.eof()) {
                delete ptr;
                break;
            }
            string k;
            getline(infile, k);
        }
    }
}

//-----------------------------------------------------------------------------
// buildCommands

void Manager::buildCommands(istream& infile) {
    
    Command* ptr = NULL;    // temp pointer to hold new Command
    char temp;
    bool successfulRead;    // read good data
    for (;;) {
        infile >> temp;
        if (commandFact.isValid(temp)) {
            ptr = commandFact.createIt(temp);
            
            successfulRead = ptr->setData(infile);
            if (infile.eof()) {
                delete ptr;
                break;
            }
            if (successfulRead) {
                
                commands.push(ptr);
            }
            else {
                delete ptr;
            }
        }
        else {
            if (infile.eof()) {
                delete ptr;
                break;
            }
            string k;
            getline(infile, k);
        }
    }
}