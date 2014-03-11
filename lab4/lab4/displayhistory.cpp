//
// displayhistory.cpp
//
// Paul Simpson
// Trevor Olson
//

#include "displayhistory.h"
#include "userfactory.h"

//-----------------------------------------------------------------------------
// constructor

DisplayHistory::DisplayHistory() {
    
}


//-----------------------------------------------------------------------------
// destructor

DisplayHistory::~DisplayHistory() {

}

//-----------------------------------------------------------------------------
// hash

int DisplayHistory::hash() const {
    return 'h' - 'a';
}

//-----------------------------------------------------------------------------
// create

Command* DisplayHistory::create() {
    return new DisplayHistory();
}

//-----------------------------------------------------------------------------
// execute

bool DisplayHistory::execute(Library &library) {
    bool success;
    NodeData* nodePtr = NULL;
    
    success = library.getUsers().retrieve(*user, nodePtr);
    
    if (success) {
        User& foundUser = static_cast<User&>(*nodePtr);
        
        vector<Command*> history = foundUser.getHistory();
        
        for (int i = 0; i < history.size(); i++) {
            cout << *history[i] << endl;
        }
    }
    
    return false;
}

//-----------------------------------------------------------------------------
// setData

bool DisplayHistory::setData(istream &data) {
    UserFactory userFact;
    user = userFact.createIt(0);
    
    user->setDataCommand(data);
    
    return true;
}

void DisplayHistory::print() const{
	cout << "history for user: " << *user;
}



