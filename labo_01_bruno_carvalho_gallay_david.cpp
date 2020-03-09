/*
-----------------------------------------------------------------------------------
Laboratory  : labo_02
File        : labo_02_carvalho_bruno_gallay_david.cpp
Author(s)   : Bruno Carvalho et David Gallay
Date        : 8.03.2020

Purpose     : Prove the good working of classes defined in others files.
Remark(s)   :
                There is the github repository:
                https://github.com/dgheig/Ba2-labo02

Compiler    : g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include "src/date.h"

using namespace std;

#define WAIT_ENTER while(cin.get()!='\n')

int main() {
    //TEST INPUT STREAM //
    {
        Date date;
    }
    cout << "TEST '=' OPERATOR" << endl;
    {
        Date date1(12,1,1990);
        cout << date1 << endl;
        Date date2 = date1;
        cout << date2 << endl;
    }
    cout << "TEST '<' OPERATOR" << endl;
    {
        Date date1(12,1,1990);
        Date date2(13, 3, 2000);
        cout << date1 << "<" << date2 << " : ";
        cout << boolalpha << (date1 < date2) << endl;
        cout << date2 << "<" << date1 << " : ";
        cout << boolalpha << (date2 < date1) << endl;
    }
    cout << "TEST '<=' OPERATOR" << endl;
    {
        Date date1(14,3,2002);
        Date date2(1,5,1980);
        cout << date1 << "<=" << date2 << " : ";
        cout << boolalpha << (date1 <= date2) << endl;
        cout << date2 << "<=" << date1 << " : ";
        cout << boolalpha << (date2 <= date1) << endl;
    }
    cout << "TEST '>' OPERATOR" << endl;
    {
        Date date1(12,1,1990);
        Date date2(13, 3, 2000);
        cout << date1 << ">" << date2 << " : ";
        cout << boolalpha << (date1 > date2) << endl;
        cout << date2 << ">" << date1 << " : ";
        cout << boolalpha << (date2 > date1) << endl;
    }
    cout << "TEST '>=' OPERATOR" << endl;
    {
        Date date1(14,3,2002);
        Date date2(1,5,1980);
        cout << date1 << ">=" << date2 << " : ";
        cout << boolalpha << (date1 >= date2) << endl;
        cout << date2 << ">=" << date1 << " : ";
        cout << boolalpha << (date2 >= date1) << endl;
    }
    cout << "TEST '==' OPERATOR" << endl;
    {
        Date date1(14,5,2000);
        Date date2(14,5,2000);
        Date date3(15,5,2000);
        cout << date1 << "==" << date2 << " : ";
        cout << boolalpha << (date1 == date2) << endl;
        cout << date1 << "==" << date3 << " : ";
        cout << boolalpha << (date1 == date3) << endl;
    }
    cout << "TEST '!=' OPERATOR" << endl;
    {
        Date date1(14,5,2000);
        Date date2(14,5,2000);
        Date date3(15,5,2000);
        cout << date1 << "!=" << date2 << " : ";
        cout << boolalpha << (date1 != date2) << endl;
        cout << date1 << "!=" << date3 << " : ";
        cout << boolalpha << (date1 != date3) << endl;
    }
    cout << "TEST '+' OPERATOR" << endl;
    {
        Date date1;
        cout << date1 << "+" << "7" << " = ";
        cout << (date1 + 7) << endl;
    }
    cout << "TEST '-' OPERATOR" << endl;
    {
        Date date1;
        cout << date1 << "-" << "22" << " = ";
        cout << (date1 - 22) << endl;
    }
    cout << "TEST '++' OPERATOR" << endl;
    {
        Date date1(15,1,1997);
        cout << "Post-increment " << date1++ << endl;
        cout << "After Post-increment " << date1 << endl;
        cout << "Pre-increment " << ++date1 << endl;
    }
    cout << "TEST '--' OPERATOR" << endl;
    {
        Date date1(15,1,1997);
        cout << "Post-decrement " << date1-- << endl;
        cout << "After Post-decrement " << date1 << endl;
        cout << "Pre-decrement " << --date1 << endl;
    }
    cout << "TEST 'string()' CAST OPERATOR" << endl;
    {
        Date date(23,8,2007);
        cout << string(date) << endl;
    }

    cout << "Please, press <ENTER> to end the program" << endl;
    WAIT_ENTER;
    return EXIT_SUCCESS;
}
