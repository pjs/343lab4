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
