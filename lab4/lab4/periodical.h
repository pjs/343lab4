//
//  periodical.h
//
//  Paul Simpson
//  Trevor Olson
//

#ifndef PERIODICAL_H
#define PERIODICAL_H

#include <iostream>
#include "item.h"

using namespace std;

class Periodical : public Item {
    
protected:
    int month;
    int year;
    
public:
    Periodical(string = "", int = 0, int = 0, int = 0);
    
    virtual int hash() const;
    virtual bool operator<(const Periodical &) const;
    virtual bool operator>(const Periodical &) const;
    //virtual bool operator<=(const Periodical &) const;
    //virtual bool operator>=(const Periodical &) const;

};

#endif
