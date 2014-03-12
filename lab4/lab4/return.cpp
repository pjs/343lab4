//
// return.cpp
//
// Paul Simpson
// Trevor Olson
//

#include "return.h"
#include <stack>
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
    if (!userPtrElsewhere)
        delete user;
    if (!itemPtrElsewhere)
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
    bool success = false;
    NodeData* nodePtr = NULL;
    
    success = library.getUsers().retrieve(*user, nodePtr);
    
    if (success) {
        User& foundUser = static_cast<User&>(*nodePtr);
        
        
        delete user;
        User* realUser = static_cast<User*>(nodePtr);
        user = realUser;
        userPtrElsewhere = true;
        
        vector<Command*>& history = foundUser.getHistory();
        
		if(history.empty()){
			success = false;
            cout << "ERROR: item hasn't been checked out,";
            cout << " can't return" << endl;
			return success;
		}
        
        int hash = item->hash();
        
        success = library.getItems(hash).retrieve(*item, nodePtr);
        
        if (success) {
            Item& foundItem = static_cast<Item&>(*nodePtr);
            stack<Command*> theStack;

			for(int i = history.size() - 1 ; i >= 0 ; i--){
				
				if(history[i]->hash() == 'r' - 'a'){
					Return* retCommand = static_cast<Return*>(history[i]);
					if(*retCommand->getItem() == foundItem){
						theStack.push(retCommand);
					}
				}
				else if(history[i]->hash() == 'c' - 'a'){
					Checkout* command = static_cast<Checkout*>(history[i]);
					if(*command->getItem() == foundItem)
						if(!theStack.empty()){
							theStack.pop();
						}
				}
			}
			if(theStack.empty()){
				success = foundItem.addItem();
                delete item;
                Item* foundItem = static_cast<Item*>(nodePtr);
                item = foundItem;
                itemPtrElsewhere = true;
				history.push_back(this);
			}else{
				cout << "ERROR: item hasn't been checked out,";
                cout << " can't return" << endl;
				success = false;
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

bool Return::setData(istream &data) {
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
void Return::print() const{
	cout << "RETURN    ";
	item->print(true);
}

//-----------------------------------------------------------------------------
// getItem
Item* Return::getItem() const{
	return item;
}

