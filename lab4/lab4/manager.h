//
//  manager.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <queue>
#include "userfactory.h"
#include "itemfactory.h"
#include "commandfactory.h"
#include "library.h"


using namespace std;

//-----------------------------------------------------------------------------
// class manager 
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
class Manager {
    
public:
    Manager();
    ~Manager();
    
    void run();
    
    
private:
    void buildUsers(istream &);
    void buildItems(istream &);
    void buildCommands(istream &);
    
    void processCommands();
    
    Library library;
    queue <Command*> commands;
    
    
    UserFactory userFact;
    ItemFactory itemFact;
    CommandFactory commandFact;
    
    
    
    
};

#endif


