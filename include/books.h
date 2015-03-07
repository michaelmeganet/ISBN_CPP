#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>

using namespace std;

class books
{
private:
    string No;
    string name;
    string Isbn;
    string Year;
public:
//    Books();
    void showName();
    void getName();
    void setName();
    void getIsbn();
    void getYear();
    void getNo();
    void putName(string Bname);
    void putIsbn(string ISBN);
    void putYear(string YEAR);
    void putNo(string Num);
   // string toString();
    books(string No, string name, string Isbn, string Year);
//  class Cat {

};  //virtual ~Books();



#endif // BOOKS_H
