//
//  command.cpp
//
//  Paul Simpson
//  Trevor Olson
//



#include "command.h"

Command::Command() {
    
}

Command::~Command() {
    
}

ostream& operator<<(ostream & output, Command& data){
	data.print();
	return output;
}
