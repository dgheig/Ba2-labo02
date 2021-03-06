/*
-----------------------------------------------------------------------------------
Laboratoire : labo_02
Fichier     : testComparisonOperators.cpp
Auteur(s)   : Bruno Carvalho et David Gallay
Date        : 24.02.2020

But         : Example of test file for comparison operator
Remarque(s) :
Compilateur : g++ 7.4.0
-----------------------------------------------------------------------------------*/

#include <iostream>
#include "../src/date.h"

using namespace std;

int exit_value = EXIT_SUCCESS;


void check(bool result, bool expected) {

    if(result != expected) {
        exit_value = EXIT_FAILURE;
        cerr << "Comparison is wrong:\n" << boolalpha
             << "Expected: " << expected << '\n'
             << "Got: "      << result
             << endl;
    } else {
        cout << "OK" << endl;
    }
}

int main() {
    Date date1(12,1,1990);
    Date date2(13, 3, 2000);
    Date date3(14,3,2002);
    Date date4(1,5,1980);


    // operator<

    cout << date1 << " < " << date2 << endl;
    check(date1 < date2, true);
    cout << endl;


    // operator<=

    cout << date3 << " <= " << date4 << endl;
    check(date3 <= date4, false);
    cout << endl;


    // operator>

    cout << date1 << " > " << date2 << endl;
    check(date1 > date2, false);
    cout << endl;


    // operator>=

    cout << date3 << " >= " << date4 << endl;
    check(date3 >= date4, true);
    cout << endl;


    // operator==

    cout << date3 << " == " << date4 << endl;
    check(date3 == date4, false);
    cout << endl;

    cout << date4 << " == " << date4 << endl;
    check(date4 == date4, true);
    cout << endl;


    // operator!=
    cout << date3 << " != " << date4 << endl;
    check(date3 != date4, true);
    cout << endl;

    cout << date4 << " != " << date4 << endl;
    check(date4 != date4, false);
    cout << endl;



    if(exit_value == EXIT_SUCCESS)
        cout << "Check were successful" << endl;
    return exit_value;
}
