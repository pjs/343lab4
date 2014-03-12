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
    bool success = false;
    NodeData* nodePtr = NULL;
    
    success = library.getUsers().retrieve(*user, nodePtr);
    
    if (success) {
        User& foundUser = static_cast<User&>(*nodePtr);
        
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
						cout << "retCommand: " << endl;
						retCommand->print();
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
				history.push_back(this);
			}else{
				cout << "ERROR: item hasn't been checked out,";
                cout << " can't return" << endl;
				success = false;
			}
        }
        else {
            cout << "ERROR: item ";
            item->print();
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

//-----------------------------------------------------------------------------
// getItem
Item* Return::getItem() const{
	return item;
}

