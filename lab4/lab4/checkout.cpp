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
    
    // only delete the user and item if they
    // haven't already been deleted
    if (!userPtrElsewhere)
        delete user;
    if (!itemPtrElsewhere)
        delete item;
}

//-----------------------------------------------------------------------------
// hash
// returns hash of the command

int Checkout::hash() const {
    return 'c' - 'a';
}

//-----------------------------------------------------------------------------
// create
// returns a clone of the checkout (for use in factory)

Command* Checkout::create() {
    return new Checkout();
}

//-----------------------------------------------------------------------------
// execute
// runs the command on a library

bool Checkout::execute(Library &library) {
    bool success;              // if the command was successful
    NodeData* nodePtr = NULL;  // temp pointer to search BinTree
    
    // get user from the library
    success = library.getUsers().retrieve(*user, nodePtr);
    
    if (success) {
        User& foundUser = static_cast<User&>(*nodePtr);
        
        // if found, delete the temporary user
        // and point user to the real user in the library
        delete user;
        User* realUser = static_cast<User*>(nodePtr);
        user = realUser;
        userPtrElsewhere = true;
        
        vector<Command*>& history = foundUser.getHistory();
        
        int hash = item->hash();
        success = library.getItems(hash).retrieve(*item, nodePtr);
        
        // if the item is found, check it out from the library
        // but only if there are some available for checkout
        if (success) {
            Item& foundItem = static_cast<Item&>(*nodePtr);
            success = foundItem.removeItem();
            if(success) {
                
                // item found! point item to the real item
                // and delete the temporary one
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
            cout << "ERROR: item" << endl;
            item->print(true);
            cout << "not found in library" << endl;
        }
        
    }
    else {
        cout << "ERROR: user ";
		user->print(true);
        cout << " not found in library" << endl;
    }
    
    return success;
}

//-----------------------------------------------------------------------------
// setData
// builds command from file

bool Checkout::setData(istream &data) {
    UserFactory userFact;  // factory for building user inside
    ItemFactory itemFact;  // factory for building item inside
    bool successfulRead;   // command built successfully
    char input;            // item type to hash check for
    
    // create user and assign the data
    user = userFact.createIt(0);
    user->setDataPartial(data);
    
    data >> input;
    
    // if it is a valid type of item
    // build it from the file
    if (itemFact.isValid(input)) {
        item = itemFact.createIt(input);
        successfulRead = item->setDataPartial(data);
        
        return successfulRead;
    }
    else {
        
        // throw away the rest of the line
        string k;
        getline(data, k);
        
        return false;
    }
}

//-----------------------------------------------------------------------------
// print
// display the information of the user and item inside the command

void Checkout::print() const {
	cout << "CHECKOUT  ";
	item->print(true);
}

//-----------------------------------------------------------------------------
// getItem
// returns the item inside the checkout

Item* Checkout::getItem() const {
	return item;
}


