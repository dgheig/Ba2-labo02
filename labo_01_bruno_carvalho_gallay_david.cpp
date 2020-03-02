/*
-----------------------------------------------------------------------------------
Laboratory  : labo_02
File        : labo_02_comte_bruno_gallay_david.cpp
Author(s)   : Bruno carvalho et David Gallay
Date        : 20.02.2020

Purpose     : Prove the good working of classes defined in others files.
Remark(s)   :

                There is the github repository:
                https://github.com/dgheig/Ba2-labo02

Compiler    : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>

#include "src/color.h"
#include "src/circle.h"
#include "src/square.h"
#include "src/rectangle.h"
#include "src/triangle.h"

using namespace std;

#define WAIT_ENTER while(cin.get()!='\n')

int main() {

    Color color(Color::Code::BLACK);

    Triangle triangle;
    Triangle triangle2 (color);
    Triangle triangle3 (Color::Code::RED);

    cout << triangle << endl;
    cout << triangle2 << endl;
    cout << triangle3 << endl;


    cout << "Please, press <ENTER> to end the program" << endl;
    WAIT_ENTER;
    return EXIT_SUCCESS;
}
