

#include "nodedata.h"

ostream& operator<<(ostream & output, NodeData& data){
	data.print(false);
	return output;
}

