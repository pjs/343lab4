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

void User::print(bool partial) const {
	if(partial){
		cout << idNumber;
	}else{
		cout << "*** Patron ID: " << idNumber << " " 
			<< lastName << " " << firstName << endl;
	}
}

void User::printHeader() const {
	
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

//-----------------------------------------------------------------------------
// getHistory

vector<Command*>& User::getHistory() {
    return history;
}

//-----------------------------------------------------------------------------
// setDataPartial

bool User::setDataPartial(istream &infile) {
    
    infile >> idNumber;
    
    return true;
}



