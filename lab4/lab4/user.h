//
//  user.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {

public:
    User();
    ~User();
    
    User* create();
    bool setData(istream &);
    
private:
    string firstName;
    string lastName;
    int number;

};

#endif


