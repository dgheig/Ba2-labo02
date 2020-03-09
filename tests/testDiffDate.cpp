/*
-----------------------------------------------------------------------------------
Laboratoire : labo_02
Fichier     : testDiffDate.cpp
Auteur(s)   : Bruno Carvalho et David Gallay
Date        : 24.02.2020

But         : Example of test file for increments, decrements
Remarque(s) :
Compilateur : g++ 7.4.0
-----------------------------------------------------------------------------------*/

#include <iostream>
#include "../src/date.h"

using namespace std;

int exit_value = EXIT_SUCCESS;

void check(int value, int expected) {

    if(value != expected) {
        exit_value = EXIT_FAILURE;
        cerr << "Difference of day is wrong:\n"
             << "Expected: " << expected << '\n'
             << "Got: "      << value
             << endl;
    } else {
        cout << "OK" << endl;
    }
}

void check(const Date& date, const Date& expected) {

    if(date != expected) {
        exit_value = EXIT_FAILURE;
        cerr << "Date value is wrong:\n"
             << "Expected: " << expected << '\n'
             << "Got: "      << date
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

    Date date5(31, 1, 2020);
    Date date6(1, 1, 2020);

    cout << date5 << " - " << date6 << endl;
    check(date5 - date6, 30);
    cout << endl;


    cout << date1 + 3713 << " - " << date2 << endl;
    check(date1 + 3713 , date2);
    cout << endl;

    cout << date1 - 3543 << " - " << date4 << endl;
    check(date1 - 3543 , date4);
    cout << endl;

    cout << date1 << "++" << endl;
    check(date1++ , Date(12,1,1990));
    check(date1 , Date(13,1,1990));
    cout << endl;

    cout << "++" << date1 << endl;
    check(++date1 , Date(14,1,1990));
    check(date1 , Date(14,1,1990));
    cout << endl;

    cout << date1 << "--" << endl;
    check(date1-- , Date(14,1,1990));
    check(date1 , Date(13,1,1990));
    cout << endl;

    cout << "--" << date1 << endl;
    check(--date1 , Date(12,1,1990));
    check(date1 , Date(12,1,1990));
    cout << endl;


    if(exit_value == EXIT_SUCCESS)
        cout << "Check were successful" << endl;
    return exit_value;
}
