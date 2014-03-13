//
//  manager.h
//
//  Paul Simpson
//  Trevor Olson
//

//-----------------------------------------------------------------------------
// class Manager
//
// The manager handles all operations with the library. It helps add the
// users to the library, items to the library and it runs through the
// commands on the library.
//
// Assumptions:
// - there is only one library
// - patron, command and item read in files are fomated properly
//
//-----------------------------------------------------------------------------

#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <queue>
#include "userfactory.h"
#include "itemfactory.h"
#include "commandfactory.h"
#include "library.h"

using namespace std;

class Manager {
    
public:
    Manager();   // constructor
    ~Manager();  // destructor
    void run();  // run entire system
    
private:
    void buildUsers(istream &);    // set users from file
    void buildItems(istream &);    // set items from file
    void buildCommands(istream &); // set commands from file
    
    void processCommands();  // process commands in queue
    
    Library library;            // holds users and items
    queue <Command*> commands;  // holds commands to be processed
    
    // factories for building users, items and commands
    UserFactory userFact;
    ItemFactory itemFact;
    CommandFactory commandFact;
    
};

#endif


