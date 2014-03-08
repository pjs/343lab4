//
//  fictionbook.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

#include <iostream>
#include "book.h"

using namespace std;

class FictionBook : public Book {
    
protected:

    
public:
    FictionBook(string = "", string = "", int = 0);
    
    virtual int hash() const;
    /*virtual bool operator<(const Item &) const;
    virtual bool operator>(const Item &) const;
    virtual bool operator<=(const Item &) const;
    virtual bool operator>=(const Item &) const;*/
};

#endif


