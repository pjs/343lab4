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

void YouthBook::print(bool partial) const {
	if(!partial){
		cout << " " << left << setw(AVAIL_OUTPUT_WIDTH) << amount;
	}
	cout << left << setw(AUTHOR_OUTPUT_WIDTH) <<
		author.substr(0,AUTHOR_OUTPUT_WIDTH) << " " << setw(TITLE_OUTPUT_WIDTH) 
		<< title.substr(0,TITLE_OUTPUT_WIDTH) << " " << setw(YEAR_OUTPUT_WIDTH) 
		<< year << endl;

}

void YouthBook::printHeader() const {
	cout << "Fiction:" << endl << setw(AVAIL_OUTPUT_WIDTH) << "AVAIL  " << 
		setw(AUTHOR_OUTPUT_WIDTH) << "AUTHOR" << setw(TITLE_OUTPUT_WIDTH) 
		<< " TITLE" << setw(YEAR_OUTPUT_WIDTH) << "  YEAR" << endl;
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

bool YouthBook::setDataPartial(istream & infile){
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

