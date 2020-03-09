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

    Date date(12,3,1980);
    cout << date << endl;
    Date date2 = date + 40;
    cout << date2.isValid() << endl;
    cout << date2 << endl;

    date = Date(1, 1, 2020);
    cout << date + 1 << endl;
    cout << date + 30 << endl;
    cout << date + (-31) << endl;

    date = Date(1, 2, 2020);
    cout << date - 1 << endl;
    cout << date - 30 << endl;
    cout << date - 31 << endl;


    cout << "Please, press <ENTER> to end the program" << endl;
    WAIT_ENTER;
    return EXIT_SUCCESS;
}
