//
//  main.cpp
//
//  Paul Simpson
//  Trevor Olson
//

#include <iostream>
#include "periodical.h"
#include "fictionBook.h"

int main()
{

    // insert code here...
    std::cout << "Hello, World!\n";
	//Periodical test("blah", 5, 12, 2013);


	FictionBook test("author", "title", 2013);
	FictionBook test2("a", "z", 2011);
	bool testbool = test < test2;
	cout << testbool;

	int i;
	cin >> i;
    return 0;

}

