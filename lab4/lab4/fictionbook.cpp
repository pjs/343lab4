//
// fictionBook.cpp
//
// Paul Simpson
// Trevor Olson
//

#include "fictionbook.h"


FictionBook::FictionBook(string author, string title, int year) : 
	Book(author, title, year){}

FictionBook::~FictionBook() {
    
}

void FictionBook::print(bool partial) const{
	if(!partial){
		cout << " " << left << setw(AVAIL_OUTPUT_WIDTH) << amount;
	}
	cout << left << setw(AUTHOR_OUTPUT_WIDTH) <<
		author.substr(0,AUTHOR_OUTPUT_WIDTH) << " " << setw(TITLE_OUTPUT_WIDTH) 
		<< title.substr(0,TITLE_OUTPUT_WIDTH) << " " << setw(YEAR_OUTPUT_WIDTH) 
		<< year << endl;
}

bool FictionBook::setData(istream & infile){
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

bool FictionBook::setDataPartial(istream & infile){
    char temp;
    infile >> temp;
    
    if (temp != 'H') {
        string k;
        getline(infile, k);
        return false;
    }
    
	infile.get();
	getline(infile, author, ',');
	infile.get();
	getline(infile, title, ',');
	infile.get();
    
	return true;
}

int FictionBook::hash() const{
	return 'f' - 'a';
}

FictionBook* FictionBook::create() {
    return new FictionBook();
}

bool FictionBook::operator<(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author < book.author) return true;
	if(this->title < book.title) return true;
	return false; 
}
bool FictionBook::operator>(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author > book.author) return true;
	if(this->title > book.title) return true;
	return false; 
}
bool FictionBook::operator<=(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author <= book.author) return true;
	if(this->title <= book.title) return true;
	return false; 
}
bool FictionBook::operator>=(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author >= book.author) return true;
	if(this->title >= book.title) return true;
	return false; 
}

bool FictionBook::operator==(const NodeData & right) const{
	const FictionBook& book = static_cast<const FictionBook&>(right);
	if(this->author == book.author &&this->title == book.title ) return true;
	return false; 
}
bool FictionBook::operator!=(const NodeData & right) const{
	return !(*this==right);
}

