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
    while(!history.empty()) {
        delete history.back();
        history.pop_back();
    }
}

//-----------------------------------------------------------------------------
// print
// print user information; if parameter is true it will only display their
// id number

void User::print(bool partial) const {
	if(partial){
		cout << idNumber;
	}else{
		cout << "*** Patron ID: " << idNumber << " " 
			<< lastName << " " << firstName << endl;
	}
}

//-----------------------------------------------------------------------------
// printHeader
// displays header of user information

void User::printHeader() const {
	
}

//-----------------------------------------------------------------------------
// create
// returns clone for use in the factory

User* User::create() {
    return new User();
}

//-----------------------------------------------------------------------------
// setData
// build user from file

bool User::setData(istream &infile) {
  
    infile >> idNumber;
    infile >> lastName;
    infile >> firstName;
    
    return true;
}

//-----------------------------------------------------------------------------
// operator==

bool User::operator==(const NodeData &right) const {
	const User& rightUser = static_cast<const User&>(right);
    
	return (idNumber == rightUser.idNumber);
}

//-----------------------------------------------------------------------------
// operator<

bool User::operator<(const NodeData & right) const{
	const User& rightUser = static_cast<const User&>(right);
    
	return (idNumber < rightUser.idNumber);
}

//-----------------------------------------------------------------------------
// operator>

bool User::operator>(const NodeData & right) const{
	const User& rightUser = static_cast<const User&>(right);
    
	return (idNumber > rightUser.idNumber);
}

//-----------------------------------------------------------------------------
// operator<=

bool User::operator<=(const NodeData & right) const{
	const User& rightUser = static_cast<const User&>(right);
    
	return (idNumber <= rightUser.idNumber);
}

//-----------------------------------------------------------------------------
// operator>=

bool User::operator>=(const NodeData & right) const{
	const User& rightUser = static_cast<const User&>(right);
    
	return (idNumber >= rightUser.idNumber);
}

//-----------------------------------------------------------------------------
// operator!=

bool User::operator!=(const NodeData & right) const{
	return !(*this==right);
}

//-----------------------------------------------------------------------------
// getHistory
// returns user's history

vector<Command*>& User::getHistory() {
    return history;
}

//-----------------------------------------------------------------------------
// setDataPartial
// builds user from partial data

bool User::setDataPartial(istream &infile) {
    
    infile >> idNumber;
    
    return true;
}



