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
    user = NULL;
}


//-----------------------------------------------------------------------------
// destructor

DisplayHistory::~DisplayHistory() {
	if (user != NULL)
		delete user;
}

//-----------------------------------------------------------------------------
// hash
// returns hash of the type of command

int DisplayHistory::hash() const {
    return 'h' - 'a';
}

//-----------------------------------------------------------------------------
// create
// returns clone of the history (for use in factory)

Command* DisplayHistory::create() {
    return new DisplayHistory();
}

//-----------------------------------------------------------------------------
// execute
// runs the history display on a library

bool DisplayHistory::execute(Library &library) {
    bool success;              // if command runs successfully
    NodeData* nodePtr = NULL;  // temp pointer to search tree
    
    // check if user is actually in the tree
    success = library.getUsers().retrieve(*user, nodePtr);
    
    // if found, loop through their history
    // and display each command
    if (success) {
        User& foundUser = static_cast<User&>(*nodePtr);
        vector<Command*> history = foundUser.getHistory();
        cout << foundUser << endl;
        
        for (int i = 0; i < history.size(); i++) {
            cout << *history[i] << endl;
        }
    }
    else {
		cout << "ERROR: user ";
		user->print(true);
        cout << " not found in library" << endl;
    }
    
    return false;
}

//-----------------------------------------------------------------------------
// setData
// builds display history command from data file

bool DisplayHistory::setData(istream &data) {
    UserFactory userFact;         // factory to build user inside
    
    // build the user and set the data to match the history
    user = userFact.createIt(0);
    user->setDataPartial(data);
    
    return true;
}

//-----------------------------------------------------------------------------
// print
// displays history for the user

void DisplayHistory::print() const{
	cout << "history for user: " << *user;
}



