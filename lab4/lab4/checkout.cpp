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
    user = NULL;
    item = NULL;
    userPtrElsewhere = false;
    itemPtrElsewhere = false;
}


//-----------------------------------------------------------------------------
// destructor

Checkout::~Checkout() {
    if (!userPtrElsewhere)
        delete user;
    if (!itemPtrElsewhere)
        delete item;
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
    
    success = library.getUsers().retrieve(*user, nodePtr);
    
    if (success) {
        User& foundUser = static_cast<User&>(*nodePtr);
        
        delete user;
        User* realUser = static_cast<User*>(nodePtr);
        user = realUser;
        userPtrElsewhere = true;
        
        vector<Command*>& history = foundUser.getHistory();
        
        
        int hash = item->hash();
        
        success = library.getItems(hash).retrieve(*item, nodePtr);
        
        if (success) {
            Item& foundItem = static_cast<Item&>(*nodePtr);
            success = foundItem.removeItem();
            if(success) {
                delete item;
                Item* foundItem = static_cast<Item*>(nodePtr);
                item = foundItem;
                itemPtrElsewhere = true;
				history.push_back(this);
            }
            else {
                cout << "ERROR: no items available for checkout" << endl;

            }
        }
        else {
            cout << "ERROR: item ";
            item->print(true);
            cout << " not found in library" << endl;
        }
        
    }
    else {
        cout << "ERROR: user " << user->getIdNumber();
        cout << " not found in library" << endl;
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
    
    user->setDataPartial(data);
    
    data >> input;
    
    if (itemFact.isValid(input)) {
        item = itemFact.createIt(input);
        
        successfulRead = item->setDataPartial(data);
        
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
void Checkout::print() const{
	cout << "CHECKOUT  ";
	item->print(true);
}

//-----------------------------------------------------------------------------
// getItem
Item* Checkout::getItem() const{
	return item;
}


