//
//  youthbook.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef YOUTHBOOK_H
#define YOUTHBOOK_H

#include <iostream>
#include "book.h"

using namespace std;

class YouthBook : public Book {
    
protected:

    
public:
    YouthBook(string = "", string = "", int = 0);
    
    virtual int hash() const;
    /*virtual bool operator<(const Item &) const;
    virtual bool operator>(const Item &) const;
    virtual bool operator<=(const Item &) const;
    virtual bool operator>=(const Item &) const;*/
};

#endif
