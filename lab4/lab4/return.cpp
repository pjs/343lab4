//
// return.cpp
//
// Paul Simpson
// Trevor Olson
//

#include "return.h"

//-----------------------------------------------------------------------------
// constructor

Return::Return() {
    
}


//-----------------------------------------------------------------------------
// destructor

Return::~Return() {

}

//-----------------------------------------------------------------------------
// hash

int Return::hash() const {
    return 'r' - 'a';
}

//-----------------------------------------------------------------------------
// create

Command* Return::create() {
    return new Return();
}

//-----------------------------------------------------------------------------
// execute

bool Return::execute(Library &library) {
    bool success;
    NodeData* nodePtr = NULL;
    
    success = library.findUser(*user, nodePtr);
    
    if (success) {
        User& foundUser = static_cast<User&>(*nodePtr);
        foundUser.addHistory(this);
    }
    
    success = library.findItem(*item, nodePtr);
    
    if (success) {
        Item& foundItem = static_cast<Item&>(*nodePtr);
        success = foundItem.addItem();
    }
    
    return success;
}

//-----------------------------------------------------------------------------
// setData

bool Return::setData(istream &data) {
    UserFactory userFact;
    ItemFactory itemFact;
    bool successfulRead;
    char input;
    user = userFact.createIt(0);
    
    user->setDataCommand(data);
    
    data >> input;
    
    if (itemFact.isValid(input)) {
        item = itemFact.createIt(input);
        
        successfulRead = item->setDataCommand(data);
        
        return successfulRead;
    }
    else {
        string k;
        getline(data, k);
        
        return false;
    }
}

//-----------------------------------------------------------------------------
// print
void Return::print() const{
	cout << "Return  " << *item;
}

