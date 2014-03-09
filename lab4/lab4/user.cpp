//
//  user.cpp
//
//  Paul Simpson
//  Trevor Olson
//


#include "user.h"

//-----------------------------------------------------------------------------
// constructor

User::User() {
    
}

//-----------------------------------------------------------------------------
// destructor

User::~User() {
    
}

//-----------------------------------------------------------------------------
// create

User* User::create() {
    return new User();
}

//-----------------------------------------------------------------------------
// setData

bool User::setData(istream &infile) {
    
    infile >> number;
    infile >> firstName;
    infile >> lastName;
    
    return true;
}

bool User::operator==(const NodeData &right) const {
	const User& user = static_cast<const User&>(right);
    
	if (number == user.number)
        return true;
    else
        return false;
}