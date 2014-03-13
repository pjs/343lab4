//
//  nodedata.cpp
//
//  Paul Simpson
//  Trevor Olson
//

#include "nodedata.h"

//-----------------------------------------------------------------------------
// operator<<

ostream& operator<<(ostream & output, NodeData& data){
	data.print(false);
	return output;
}

//-----------------------------------------------------------------------------
// destructor

NodeData::~NodeData() {

}