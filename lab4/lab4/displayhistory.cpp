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
    
    success = library.findUser(*user, nodePtr);
    
    if (success) {
        User& foundUser = static_cast<User&>(*nodePtr);
        
        foundUser.displayHistory();
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

