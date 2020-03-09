/*
-----------------------------------------------------------------------------------
Laboratoire : labo_02
Fichier     : testSetters.cpp
Auteur(s)   : Bruno Carvalho et David Gallay
Date        : 24.02.2020

But         : Example of test file for a function
Remarque(s) :
Compilateur : g++ 7.4.0
-----------------------------------------------------------------------------------*/

#include <iostream>
#include "../src/date.h"

using namespace std;

int exit_value = EXIT_SUCCESS;


void check(const Date& date, bool expected) {

    if(date.isValid() != expected) {
        exit_value = EXIT_FAILURE;
        cerr << "Date validity is wrong:\n" << boolalpha
             << date << '\n'
             << "Expected: " << expected
             << "Got: "      << date.isValid()
             << endl;
    }
}

void check(const Date& date, const Date& expected) {

    if(date != expected) {
        exit_value = EXIT_FAILURE;
        cerr << "Date value is wrong:\n"
             << "Expected: " << expected
             << "Got: "      << date
             << endl;
    }
}

int main() {

    Date a(31, 1, 2020);
    a.setMonth(Month::AUGUST);
    check(a, Date(31, Month::AUGUST, 2020));

    a.setDay(34);
    check(a, false);

    if(exit_value == EXIT_SUCCESS)
        cout << "Check were successful" << endl;
    return exit_value;
}
