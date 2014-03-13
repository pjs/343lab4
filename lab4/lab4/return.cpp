//
// return.cpp
//
// Paul Simpson
// Trevor Olson
//

#include <stack>
#include "return.h"
#include "checkout.h"

//-----------------------------------------------------------------------------
// constructor

Return::Return() {
    user = NULL;
    item = NULL;
    userPtrElsewhere = false;
    itemPtrElsewhere = false;
}


//-----------------------------------------------------------------------------
// destructor

Return::~Return() {
    
    // only delete the user and item if they haven't
    // already been deleted somewhere else
    if (!userPtrElsewhere)
        delete user;
    if (!itemPtrElsewhere)
        delete item;
}

//-----------------------------------------------------------------------------
// hash
// gets a hash of the type of command

int Return::hash() const {
    return 'r' - 'a';
}

//-----------------------------------------------------------------------------
// create
// returns a clone of the return (for use in the factory)

Command* Return::create() {
    return new Return();
}

//-----------------------------------------------------------------------------
// execute

bool Return::execute(Library &library) {
    bool success = false;      // if the execution doesn't have any errors
    NodeData* nodePtr = NULL;  // temp pointer to find data in BinTree
    
    // see if user exists in the library
    success = library.getUsers().retrieve(*user, nodePtr);
    
    if (success) {
        User& foundUser = static_cast<User&>(*nodePtr);
        
        // matching user was found so we can
        // assign user to the real user in the library
        delete user;
        User* realUser = static_cast<User*>(nodePtr);
        user = realUser;
        userPtrElsewhere = true;
        
        // now check the history of that user
        // to see if they have checked out the item
        vector<Command*>& history = foundUser.getHistory();
        
        // match checkout not found
		if(history.empty()){
			success = false;
            cout << "ERROR: item hasn't been checked out,";
            cout << " can't return" << endl;
			return success;
		}
        
        // get hash of item and search library
        int hash = item->hash();
        success = library.getItems(hash).retrieve(*item, nodePtr);
        
        
        // if found, check to see there is a matching checkout
        // using a stack to allow for a item being checked out
        // and returned many times
        if (success) {
            Item& foundItem = static_cast<Item&>(*nodePtr);
            stack<Command*> theStack;

			for(int i = history.size() - 1 ; i >= 0 ; i--) {
				if(history[i]->hash() == 'r' - 'a') {
					Return* retCommand = static_cast<Return*>(history[i]);
					if(*retCommand->getItem() == foundItem) {
						theStack.push(retCommand);
					}
				}
				else if(history[i]->hash() == 'c' - 'a') {
					Checkout* command = static_cast<Checkout*>(history[i]);
					if(*command->getItem() == foundItem)
						if(!theStack.empty()) {
							theStack.pop();
						}
				}
			}
            
			if(theStack.empty()) {
				success = foundItem.addItem();
                delete item;
                Item* foundItem = static_cast<Item*>(nodePtr);
                item = foundItem;
                itemPtrElsewhere = true;
				history.push_back(this);
			} else {
				cout << "ERROR: item hasn't been checked out,";
                cout << " can't return" << endl;
				success = false;
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
// set data for the return command from a file of commands

bool Return::setData(istream &data) {
    UserFactory userFact;  // to build user inside command
    ItemFactory itemFact;  // to build item inside command
    bool successfulRead;   // valid data is read
    char input;            // command type
    
    
    // build user
    user = userFact.createIt(0);
    user->setDataPartial(data);
    
    data >> input;
    
    // if the item type exists, build the item
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
// displays the item and user information inside the return command

void Return::print() const {
	cout << "RETURN    ";
	item->print(true);
}

//-----------------------------------------------------------------------------
// getItem
// returns the item inside the return command

Item* Return::getItem() const {
	return item;
}

