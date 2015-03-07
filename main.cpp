#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <fstream>
#include "books.h"
#include "BooksArray.h"
using namespace std;
string tempArray[2] ;
void ClearScreen()
{
    cout << string( 100, '\n' );
}
void PressAnyKeyToContinue()
{
       string input;
       cout << "Press any key (a - z) then press enter to continue. . .\n" << flush;
       cin >> input;
       cin.clear();

}

string NumberToString ( int Number );// convert integer to string
/*void mypause ( void )
{
  printf ( "Press [Enter] to continue . . ." );
  fflush ( stdout );
  getchar();
}
*/
//int array_size = 3200; // define the size of character array
///  char B_array[array_size];
//char * array = new char[array_size];
//char * array = B_array; // allocating an array of 1kb

//int iSize = 10;


/////////////////////init the Mystr ////////////////////////////
//string Mystr[11]={"*","*","*","*","*","*","*","*","*","*","*"};

int j;
//int mm = 0; // init the counter mm

int records = 0;
int cut_off_point;
int main()
{
    const string password = "hello";




	string input;

	do {
		cout << "Enter your password > " << flush;
		cin >> input;

		if(input != password) {
			cout << "Access denied." << endl;
		}

	} while (input != password);


        cout << "Password accepted" << endl;
        cout << "Please wait, reading .dat file now ........" << endl;
////////// read .dat file and put it into array////////////////////////////////


    int array_size = 3200; // define the size of character array
	char * array = new char[array_size]; // allocating an array of 1kb
	int position = 0; //this will be used incremently to fill characters in the array
	int counter = 1;
	int t = 0;
	string Mystr[400];
	string SortArray[410];
	int del_record_no;
	//ifstream fin("file.dat"); //opening an input stream for file test.txt
	/*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
  stream could not be opened.*/
    //int i;
  // for(i=0; i < array_size; i++){
    //    array[i] = 0;
   // }
    /*
    for(i=0; i < sizeof(array)/sizeof(array[0]); i++){
        cout << array[i] << endl;
    }
    */
    int TotalLine = 0;
    int mm = 0;
    ifstream fin("file.dat"); //opening an input stream for file test.txt
    if(fin.is_open())
    {
        j = 0;
        //file opened successfully so we are here
        cout << "File Opened successfully!!!. Reading data from file into array" << endl;
        //this loop run until end of file (eof) does not occur
        while(!fin.eof() && position < array_size)
        {
            fin.get(array[position]); //reading one character from file to array
            position++;
        }
        array[position-1] = '\0'; //placing character array terminating character

        cout << "Reading file.dat into  Array........" << endl << endl;
        //this loop display all the charaters in array till \0
        for(int i = 0; array[i] != '\0'; i++)
        {
            cout << array[i];

            if (array[i]== '\n')
            {
                mm++;
               // cout << "mm = " << mm << endl;
            }
            else
            {



            }


        }
        fin.close();
        cout << "------------End of Displaying array --------------------" << endl;
        records = mm /4;
        cout << "Total records is " << records<< endl;

       // cout << "Size of array " << sizeof(array) << endl;
        //cout << "sizeOfarray = " << sizeOfarray << endl;
        //char *p = array;
       // cout << "Assign the elements into Mystr[] array" << endl;
        int m = 0;
        TotalLine = mm;

        cout <<"TotalLine is " << TotalLine << endl;

        for (int n=0; n < TotalLine; n++)
        {

            do
            {
                //set n = o, then append each array[m] into Mystr[n]; m++ until get "\n";
                //then n++ and start Mystr[n] += array[m] again
                Mystr[n] += array[m] ;
                m++;

            }
            while (array[m] !='\n');
            std::string str1 = Mystr[n];
            str1.erase(std::remove(str1.begin(), str1.end(), '\n'),
            str1.end());
            Mystr[n] = str1;
        }
    }
    else //file could not be opened
    {
        cout << "File could not be opened." << endl;

    }

    cout << "\n" << "\n" << endl;
    cout << "size of Mystr = " << sizeof(Mystr) << endl;
    cout << "size of Mystr(0) = " <<  sizeof(Mystr[0]) << endl;
    cout << "  size of Mystr/ size of Mystr(0) = " << sizeof(Mystr)/sizeof(Mystr[0]) << endl;
    //////////////////////////////////////////////////////////////
        //cout << "the position of the array's pointer is at " << position << endl;


	///////////////////////////// end of open and read file into array////////////////////////


	// MAIN MENU
    cout << "1.\tAdd new record." << endl;
    cout << "2.\tDelete record." << endl;
    cout << "3.\tView record." << endl;
    cout << "4.\tSearch record." << endl;
    cout << "5.\tQuit." << endl;
    cout << "6.\tWrite record to hard disk." << endl;
    books book2("1","AAAAAAAAAAAA", "1254658978", "2001");
    books book1("2","fddffdf", "1212121212","2121");
    //bool Found2= false;
    int value;
    string Num;
    string bookName;
    string ISBN ;
    string YEAR ;
    std::string Input2;
    int value2;
    value2 = 0;
    const int Counter = 4;
    del_record_no = 0;
    ofstream writer("file3.dat");
    do {
        cout << "Enter your selection > " << flush;
        cin >> value;
        switch(value)
        {
        case 1:
             int AddM;
             AddM = TotalLine;
            cout << "TotalLine = " << TotalLine << endl;
             AddM;
             //string sss;
             //cout << "mm = " << mm << endl;
             cout << "Please enter the append number " << TotalLine /4 + 1 << endl;

            cin >> Num;
            cout << "AddM = " << AddM << endl;

            Mystr[AddM] = Num;
            cout << "Enter the book's name : " ;
            cin.ignore();
            //cin >> bookName;
            //std::cin.sync(); //clear buffer

            getline (cin, bookName);
            //std::getline (std::cin,bookName);
            //cin.getline (bookName,256);


            //cout << bookName << endl;
            AddM++;
            Mystr[AddM] = bookName; // put bookName to tempArray for save in HD
            book2.putName(bookName);
            cout << "Enter the ISBN number : " ;
            //cin >> ISBN;
            getline (cin, ISBN);
            AddM++;
            Mystr[AddM] = ISBN;
            book2.putIsbn(ISBN);
            //cout << ISBN << endl;

            cout << "Enter the year of publish : ";
            //cin >> YEAR;
            getline (cin, YEAR);
            AddM++;
            Mystr[AddM] = YEAR;
            book2.putYear(YEAR);

            cout << "The name you key in is : " << endl;
            book2.getName();
            cout << "The ISBN you key in is : " << endl;
            book2.getIsbn();
            cout << "The year is : " << endl;
            book2.getYear();
            mm = AddM +1;
            TotalLine = mm;
            //cout << "mm = " << mm << endl;
            cout << "The new record is added." << endl;

            break;
        case 2:

             do {
                cout << "1. delete by record number"<< endl;
                cout << "2. delete by ISBN number " << endl;
                cout << "3. End delete data"<< endl;
                cout << "Enter your selection > " << flush;
                cin >> value;
                string del_record;
                cut_off_point = 0;
                switch(value)
                {
                    case 1:
                        cout << "Please enter the record number that you want to delete." << flush;
                        cin >> del_record;
                        cout << "the key you enter is " << del_record << endl;
                    for(int i =0; i < TotalLine+1; i++)
                    {

                        string str = Mystr[i];
                        t = (i+1)  % Counter ;
                        bool Found2;
                        Found2 = false;
                        int del_confirm;
                        int k;

                        del_confirm = 0;
                        if (t == 1)
                        {
                             del_record_no = i;
                             cout << "the variable i = " << i << endl;
                             cout << "the variable del_recore_no = " << del_record_no << endl;

                            std::size_t found = str.find(del_record);
                            if (found!=std::string::npos)
                            {
                                std::cout << "Record no : " << del_record <<" found " <<  '\n';
                                Found2 = true;

                                cout <<"Record no : " << Mystr[i] << '\n';
                                cout <<"Book name : " << Mystr[i+1] <<'\n';;
                                cout <<"ISBN   No : " << Mystr[i+2] << '\n';;
                                cout <<" Year of Published : " << Mystr[i+3] <<'\n';

                                cout << "Mystr[i] = Record no : " << Mystr[i] << "i  = "<< i<< endl;
                                cout <<"are you sure you want to delete? press 1 to continue!" << flush;
                                cin >> del_confirm;
                                cut_off_point = i + 4;
                                cout << "Do the delete work.............."<< endl;
                                if (del_confirm == 1)
                                {
                                    for (int j =0; j < i  ; j++)
                                    {

                                        SortArray[j] = Mystr[j];
                                        //cout << "SortArray[j] = "<< SortArray[j] << endl;
                                    }
                                    int tt;
                                     if (SortArray[k] != "\n")
                                     {
                                        cout << "TotalLine = "<< TotalLine << endl;
                                        for (int k = cut_off_point -4; k < TotalLine-4 ; k++ )
                                        {
                                            tt = (k+1)  % Counter ;
                                            cout << "tt = " << tt << endl;

                                                if (tt == 1)
                                                {
                                                    SortArray[k] = Mystr[k];
                                                    cout << "Mystr[" << k << "] = "<< Mystr[k] << endl;
                                                    cout << "SortArray["<<k <<"] = "<< SortArray[k]<<endl;
                                                }
                                                else
                                                {
                                                    SortArray[k] = Mystr[k+4];

                                                    cout << "SortArray["<<k <<"] = "<< SortArray[k]<< "Mystr[" << k+4 << "] = "<< Mystr[k+4] << endl;
                                                }

                                        }
                                    }
                                         //cout << "end of before cutoff " << endl;
                                    /*int tt;
                                    for (int k = cut_off_point -8; k < TotalLine ; k++ )
                                    {
                                        tt = (k+1)  % Counter ;
                                        //cout << "tt = " << tt << endl;
                                        //cout << " k (cut Off Point) = " << k << endl;
                                        if (tt == 1){
                                        SortArray[k] = Mystr[k-4];
                                     //   cout << "SortArray[k] = " << SortArray[k] << endl;
                                        }
                                        else{
                                         SortArray[k]= Mystr[k];
                                        //cout << "SortArray[k] = " << SortArray[k] << endl;

                                        }
                                        SortArray[k] = Mystr[k-4];

                                    }*/
                                    for (int l=0; l < TotalLine; l++)
                                        {
                                            Mystr[l] = "";
                                            // clear Mystr[] before update from SortArray[]
                                        }

                                    cout << "do a sorting of all records because of the delete of this record." << endl;
                                    for (int j =0; j < TotalLine  ; j++)
                                    {


                                       // cout <<  "SortArray[" << j << "]  = "<<  SortArray[j]<< endl;
                                        cout << "adding ....  " << SortArray[j] << "  ...............into Mystr[" << j << "]   " << endl;

                                       // if (SortArray[j] !=""){

                                            Mystr[j] = SortArray[j];
                                      // }

                                    }



                                    cout << "sorting done, Mystr[] order is in place now."<< endl;
                                    for (int j=0; j < TotalLine; j++)
                                    {
                                        cout <<"Mystr[" << j << "] = "<< Mystr[j]<< endl;

                                    }


                                    //cout << "the variable i = " << i << endl;
                                    //cout << "the variable del_record_no = " << del_record_no << endl;
                                    cout << "before minus 4, TotalLine = "<< TotalLine <<endl;

                                    TotalLine = TotalLine - 4;
                                    cout << "after minus 4  TotalLine  = " << TotalLine << endl;
                                    break;


                                }
                            }
                            // cout << "ISBN is " << Input << endl;

                        }



                    }


                        cout << "The record has been deleted by record number." << endl;
                        break;
                    case 2:

                        cout << "The record has been deleted by ISBN number." << endl;
                        break;
                    case 3:
                        cout << "you are quit from delete record" << endl;
                        break;
                    default:
                        cout << "Unrecognised value." << endl;
                        break;

                }
                }while (value != 3);


            break;
        case 3:
       /*     for(int i = 0; array[i] != '\0'; i++)
            {
                if(array[i] == '1' )
                {
                    cout << array[i];
                    cout << array[i+1];
                    cout << array[i+2];
                }
                //cout << "i = " << i << endl;

            }*/
            int k ;
            k = 1;
            cout << "Display the value of Mystr " << "\n" <<endl;
            int tt ;
            tt = 0;
            cout << "===================" << k <<"==========================" << endl;
            //cout << "TotalLine = " << TotalLine << endl;
            for(int i =0; i < TotalLine+1; i++)


            {


                if (Mystr[i] != "")
                {

                    const int Counter = 4;

                    tt = (i+1)  % Counter ;
                //cout << "tt = " << tt << endl;
                    switch(tt)
                    {
                    case 0:

                        cout <<  Mystr[i] << endl;
             //           cout << "this is case zero  " << Mystr[i] << endl;
                        k++;
                       // cout << "mm /4 + 1" << mm/4+1 << endl;
                        if (k < (TotalLine/4) +1 )
                        {
                            cout << "===================" << k <<"==========================" << endl;
                            //cout << "mm = "<< mm << endl;
                        }
                        else
                        {

                        }
                        break;
                    case 1:
                       // cout << "No." << Mystr[i] << endl;
                        cout << Mystr[i] << endl;
               //         cout << "this is case 1  " << Mystr[i] << endl;
                        break;
                    case 2:
                       //  cout << "The name of the book is " << Mystr[i] << endl;
                        cout << Mystr[i] << endl;
                 //       cout << "this is case 2  " << Mystr[i] << endl;
                        break;
                    case 3:
                      //  cout << "The ISBN Number is" <<Mystr[i] << endl;
                        cout <<Mystr[i] << endl;
                   //     cout << "this is case 3  " << Mystr[i] << endl;
                        break;


                    }


                }

            };
            cout << "===============END OF RECORDS================" << endl;
            cout << "You have view all records." << endl;

            //cout << "===============END OF RECORDS================" << endl;
            cout << "the array Mystr[" << mm <<"] " << Mystr[mm] << "is the last array."<< "\n" << endl;
            break;
        case 4:
            //string Input2 ="";
            cout << "Enter the ISBN number you want to search > " << flush;
            cin >> Input2;
            bool Found2  ;
            for(int i =0; i < TotalLine; i++)
            {

                string str = Mystr[i];
                t = (i+1)  % Counter ;
                if (t == 3)
                {
                    std::size_t found = str.find(Input2);
                    if (found!=std::string::npos)
                    {
                        std::cout << "ISBN NUMBER " << Input2 <<" found " << found << " record(s)"<< '\n';
                        Found2 = true;

                        cout <<"Record no : " << Mystr[i-2] << '\n';
                        cout <<"Book name : " << Mystr[i-1] <<'\n';;
                        cout <<"ISBN   No : " << Mystr[i] << '\n';;
                        cout <<" Year of Published : " << Mystr[i+1] <<'\n';
                    }
                    // cout << "ISBN is " << Input << endl;

                }
            }

            if (!Found2)
            {
                cout << "Not found any book with ISBN number = " << Input2 << " in the database.";
            }



            cout << "You have search the record." << endl;
            break;
        case 5:
            cout << "You are quiting ...." << endl;
            break;
        case 6:

            cout << "Write the result to harddrive now!" << endl;
      //  SaveToHardDisk( TotalLine, Mystr);
            if(writer.is_open())

            {
                 for(int i =0; i < TotalLine+1; i++){

                    std::string str1 = Mystr[i];
                    str1.erase(std::remove(str1.begin(), str1.end(), '\n'),
                    str1.end());
                    if (str1!=""){
                        writer << str1 << '\n';
                    }



                 }
                              //  writer << bookName << " " << ISBN << " "<<YEAR << "\n"<< endl;
               // writer << tempArray[0] << " " << ISBN << " "<<YEAR << "\n"<< endl;
                cout << "Writing was success!" << endl;
            }
            else{

                cout << "Error" << endl;

            }
            writer.close();
            break;

        default:
            cout << "Unrecognised value." << endl;
            break;

        }
       // mypause();
        PressAnyKeyToContinue();
       // ClearScreen();
        cout << "1.\tAdd new record." << endl;
        cout << "2.\tDelete record." << endl;
        cout << "3.\tView record." << endl;
        cout << "4.\tSearch record." << endl;
        cout << "5.\tQuit." << endl;
        cout << "6.\tWrite record to hard disk." << endl;
    }
    while (value != 5);

    return 0;
}
template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }
