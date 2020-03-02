/*
-----------------------------------------------------------------------------------
Laboratoire : labo_02
Fichier     : test_rectangle.cpp
Auteur(s)   : Bruno carvalho et David Gallay
Date        : 24.02.2020

But         : Test features of class Rectangle
Remarque(s) :
Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#include <iostream>
#include "../src/color.h"
#include "../src/rectangle.h"
using namespace std;


int main() {

    Color c(Color::Code::GREEN);

    Rectangle rect1;
    Rectangle rect2(5);
    Rectangle rect3(7, 9);
    Rectangle rect4(7, 9, c);
    Rectangle rect5(Color::Code::BLACK);
    Rectangle rect6(c);

    cout << rect1 << endl;
    cout << rect2 << endl;
    cout << rect3 << endl;
    cout << rect4 << endl;
    cout << rect5 << endl;
    cout << rect6 << endl;

    if(rect1.setWidth(9).getWidth() != 9)
        return EXIT_FAILURE;

    if(rect2.setColor(c).getColor().getColorCode() != c.getColorCode())
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
