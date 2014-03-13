//
//  manager.cpp
//
//  Paul Simpson
//  Trevor Olson
//

#include "manager.h"
#include "user.h"
#include <fstream>

using namespace std;

//-----------------------------------------------------------------------------
// constructor

Manager::Manager() {
    
}

//-----------------------------------------------------------------------------
// destructor

Manager::~Manager() {

}

//-----------------------------------------------------------------------------
// run
// builds data from files and runs the commands

void Manager::run() {
    ifstream userFile("data4patrons.txt");
    buildUsers(userFile);

	ifstream itemFile("data4books.txt");
	buildItems(itemFile);
    
    ifstream commandFile("data4commands.txt");
	buildCommands(commandFile);
    
    processCommands();
}

//-----------------------------------------------------------------------------
// buildUsers
// builds users from data file

void Manager::buildUsers(istream& infile) {
    
    User* ptr = NULL;       // temp pointer to hold new User
    bool successfulRead;    // read good data
    for (;;) {
        ptr = userFact.createIt(0);
        successfulRead = ptr->setData(infile);
        if (infile.eof()) {
            delete ptr;
            break;
        }
        
        if (successfulRead) {
            
            // add user to library
            bool success = library.getUsers().insert(ptr);
			if(!success)
					delete ptr;
        }
        else {
            delete ptr;
        }
    }
}

//-----------------------------------------------------------------------------
// buildItems
// set item data from file

void Manager::buildItems(istream& infile) {
    
    Item* ptr = NULL;       // temp pointer to hold new Item
    char temp;              // hold item type
    bool successfulRead;    // read good data
    for (;;) {
        infile >> temp;
        if (itemFact.isValid(temp)) {
            ptr = itemFact.createIt(temp);
            
            successfulRead = ptr->setData(infile);
            if (infile.eof()) {
                delete ptr;
                break;
            }
            
            if (successfulRead) {
                int hash = ptr->hash();
                
                // add item to library
                bool success = library.getItems(hash).insert(ptr);
				if(!success)
					delete ptr;
            }
            else {
                delete ptr;
            }
        }
        else {
            if (infile.eof())
                break;
            
            cout << "ERROR: " << temp << " is not a valid item code" << endl;
            string k;
            getline(infile, k);
        }
    }
}

//-----------------------------------------------------------------------------
// buildCommands
// set command data from a file

void Manager::buildCommands(istream& infile) {
    
    Command* ptr = NULL;    // temp pointer to hold new Command
    char temp;              // type of command
    bool successfulRead;    // read good data
    for (;;) {
        infile >> temp;
        if (commandFact.isValid(temp)) {
            ptr = commandFact.createIt(temp);

            successfulRead = ptr->setData(infile);
            if (infile.eof()) {
                delete ptr;
                break;
            }
            if (successfulRead) {
                
                // add to queue
                commands.push(ptr);
            }
            else {
                delete ptr;
            }
        }
        else {
            if (infile.eof())
                break;
            
            cout << "ERROR: " << temp << " is not a valid action code" << endl;
            
            string k;
            getline(infile, k);
        }
    }
}

//-----------------------------------------------------------------------------
// processCommands
// runs commands inside the queue

void Manager::processCommands() {
    Command* currentCommand = NULL;   // current action to run
    bool result;                      // should result be deleted
    
    // run until all commands processed
    while (!commands.empty()) {
        
        currentCommand = commands.front();
        commands.pop();
        
        result = currentCommand->execute(library);
        
        if (!result) {
           delete currentCommand;
        }
        
    }
    
}

