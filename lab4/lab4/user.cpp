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
// print

void User::print() const {
    cout << idNumber << " " << lastName << " " << firstName << endl;
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
    infile >> lastName;
    infile >> firstName;
    
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

