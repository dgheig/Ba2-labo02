/*
-----------------------------------------------------------------------------------
Laboratoire : labo_02
Fichier     : testDiffDate.cpp
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


int main() {

    Date a(31, 1, 2020);
    Date b(1, 1, 2020);

    cout << a - b << endl;

    return exit_value;
}
