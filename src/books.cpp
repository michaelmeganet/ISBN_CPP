#include <iostream>
#include "books.h"

using namespace std;

books::books(string No, string name, string Isbn, string Year){
    this->No = No;
    this->name = name;
    this->Isbn = Isbn;
    this->Year = Year;
    }

void books::showName(){
	cout << "My name is around the world in 80 days" << endl;
}

void books::getName() {
	//cout << "Meouwww!!!" << endl;
	cout << name << endl;
}

void books::getIsbn() {
	//cout << "Meouwww!!!" << endl;
	cout << Isbn << endl;
}

void books::getYear(){
    cout << Year << endl;
}
void books::getNo(){
    cout << No << endl;
}
//void setName(string name) {
//		this->name = name;
//	}
void getName(string name) {
    cout << name << endl;
}

void books::putName(string Bname){
    name = Bname;
}

void books::putIsbn(string ISBN) {
    Isbn = ISBN;
}
void books::putYear(string YEAR) {
    Year = YEAR;
}
void books::putNo(string Num) {
    No = Num;
}
