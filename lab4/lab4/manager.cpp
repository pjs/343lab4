//
//  manager.cpp
//
//  Paul Simpson
//  Trevor Olson
//


#include "manager.h"
#include "user.h"


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