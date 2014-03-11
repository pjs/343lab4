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
            stack<Command*> theStack;

			for(int i = history.size() ; i >= 0 ; i--){
				
				if(history[i]->hash() == 'r'){
					Return* retCommand = static_cast<Return*>(history[i]);
					if(*retCommand->item == foundItem)
						theStack.push(retCommand);
				}
				else if(history[i]->hash() == 'c'){
					Checkout* command = static_cast<Checkout*>(history[i]);
					if(*command->item == foundItem)
						if(theStack.pop()==NULL){
							success = foundItem.addItem();
							history.push_back(this);
						}else{
							success = false;
						}
				}
			}
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

