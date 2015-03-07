#include <iostream>
#include "BooksArray.h"

using namespace std;
BooksArray::BooksArray(string No, string name, string Isbn, string Year){
    this->No = No;
    this->name = name;
    this->Isbn = Isbn;
    this->Year = Year;
    }

BooksArray::~BooksArray()
{
    //dtor
}


void BooksArray::getName() {
	//cout << "Meouwww!!!" << endl;
	cout << name << endl;
}

void BooksArray::getIsbn() {
	//cout << "Meouwww!!!" << endl;
	cout << Isbn << endl;
}

void BooksArray::getYear(){
    cout << Year << endl;
}
