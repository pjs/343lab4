//
//  manager.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "userfactory.h"
#include "library.h"

using namespace std;

class Manager {
    
public:
    Manager();
    ~Manager();
    
    void run();
    
    
private:
    void buildUsers(istream &);
    
    Library library;
    
    UserFactory userFact;
    
    
    
};

#endif
