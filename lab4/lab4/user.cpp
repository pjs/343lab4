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
  
    infile >> idNumber;
    infile >> firstName;
    infile >> lastName;
    
    return true;
}

bool User::operator==(const NodeData &right) const {
	const User& rightUser = static_cast<const User&>(right);
    
	return (idNumber == rightUser.idNumber);
}

bool User::operator<(const NodeData & right) const{
	const User& rightUser = static_cast<const User&>(right);
    
	return (idNumber < rightUser.idNumber);
}
bool User::operator>(const NodeData & right) const{
	const User& rightUser = static_cast<const User&>(right);
    
	return (idNumber > rightUser.idNumber);
}
bool User::operator<=(const NodeData & right) const{
	const User& rightUser = static_cast<const User&>(right);
    
	return (idNumber <= rightUser.idNumber);
}
bool User::operator>=(const NodeData & right) const{
	const User& rightUser = static_cast<const User&>(right);
    
	return (idNumber >= rightUser.idNumber);
}

bool User::operator!=(const NodeData & right) const{
	return !(*this==right);
}

