//
//  youthbook.cpp
//
//  Paul Simpson
//  Trevor Olson
//

#include "youthbook.h"

YouthBook::YouthBook(string author, string title, int year)
	:Book(author, title, year){}


int YouthBook::hash() const{
	return 'y' - 'a';
}

YouthBook::~YouthBook() {
    
}

void YouthBook::print() const {
	cout << setw(5) << amount << setw(20) << author << setw(30) << title <<
	setw(4) << year << endl;
}

void YouthBook::printHeader() const {
	cout << "Youth:" << endl << setw(5) << "AVAIL" << setw(20)
    << "AUTHOR" << setw(30) << "TITILE" << setw(4) << "YEAR" << endl;
}

bool YouthBook::setData(istream & infile){
    amount = AMOUNT;
	infile.get();
	getline(infile, author, ',');
	infile.get();
	getline(infile, title, ',');
	infile.get();
	infile >> this->year;
    infile.get();
	return true;
}

bool YouthBook::setDataCommand(istream & infile){
    char temp;
    infile >> temp;
    
    if (temp != 'H') {
        string k;
        getline(infile, k);
        return false;
    }
    
	infile.get();
	getline(infile, title, ',');
	infile.get();
	getline(infile, author, ',');
	infile.get();
    
	return true;
}

YouthBook* YouthBook::create() {
    return new YouthBook();
}

bool YouthBook::operator<(const NodeData & right ) const{
	const YouthBook& book = static_cast<const YouthBook&>(right);
	if(this->title < book.title) return true;
	if(this->author < book.author) return true;
	return false;
}
bool YouthBook::operator<=(const NodeData & right ) const{
	const YouthBook& book = static_cast<const YouthBook&>(right);
	if(this->title <= book.title) return true;
	if(this->author <= book.author) return true;
	return false;
}
bool YouthBook::operator>(const NodeData & right ) const{
	const YouthBook& book = static_cast<const YouthBook&>(right);
	if(this->title > book.title) return true;
	if(this->author > book.author) return true;
	return false;
}
bool YouthBook::operator>=(const NodeData & right ) const{
	const YouthBook& book = static_cast<const YouthBook&>(right);
	if(this->title >= book.title) return true;
	if(this->author >= book.author) return true;
	return false;
}
bool YouthBook::operator==(const NodeData & right ) const{
	const YouthBook& book = static_cast<const YouthBook&>(right);
	if(this->title == book.title && this->author == book.author) return true;
	return false;
}
bool YouthBook::operator!=(const NodeData & right ) const{
	return !(*this==right);
}

