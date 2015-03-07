#ifndef BOOKSARRAY_H
#define BOOKSARRAY_H
#include <iostream>

using namespace std;

class BooksArray
{
    private:
        string No;
        string name;
        string Isbn;
        string Year;
    public:
        BooksArray();
        virtual ~BooksArray();
     //   bookArray[10];
         void showName();
        void getName();
        void setName();
        void getIsbn();
        void getYear();
        void getNo();
   // string toString();
    BooksArray(string No, string name, string Isbn, string Year);


};

#endif // BOOKSARRAY_H
