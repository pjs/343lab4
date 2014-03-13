//
//  command.cpp
//
//  Paul Simpson
//  Trevor Olson
//

#include "command.h"

//-----------------------------------------------------------------------------
// constructor

Command::Command() {
    
}

//-----------------------------------------------------------------------------
// destructor

Command::~Command() {
    
}

//-----------------------------------------------------------------------------
// operator<<

ostream& operator<<(ostream & output, Command& data){
	data.print();
	return output;
}


