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
    user = NULL;
    item = NULL;
}


//-----------------------------------------------------------------------------
// destructor

Return::~Return() {
	if (user != NULL)
        delete user;
    
    if (item != NULL)
        delete item;
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
    
    success = library.getUsers().retrieve(*user, nodePtr);
    
    if (success) {
        User& foundUser = static_cast<User&>(*nodePtr);
        
        vector<Command*>& history = foundUser.getHistory();
        
        
        int hash = item->hash();
        
        success = library.getItems(hash).retrieve(*item, nodePtr);
        
        if (success) {
            Item& foundItem = static_cast<Item&>(*nodePtr);
            success = foundItem.addItem();
            history.push_back(this);
        }
        
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

