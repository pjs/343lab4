//
// checkout.cpp
//
// Paul Simpson
// Trevor Olson
//

#include "checkout.h"

//-----------------------------------------------------------------------------
// constructor

Checkout::Checkout() {
    
}


//-----------------------------------------------------------------------------
// destructor

Checkout::~Checkout() {

}

//-----------------------------------------------------------------------------
// hash

int Checkout::hash() const {
    return 'c' - 'a';
}

//-----------------------------------------------------------------------------
// create

Command* Checkout::create() {
    return new Checkout();
}

//-----------------------------------------------------------------------------
// execute

bool Checkout::execute(Library &library) {
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
        success = foundItem.removeItem();
    }
    
    return success;
}

//-----------------------------------------------------------------------------
// setData

bool Checkout::setData(istream &data) {
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


