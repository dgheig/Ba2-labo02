/*
-----------------------------------------------------------------------------------
Laboratoire : labo_02
Fichier     : test_circle.cpp
Auteur(s)   : Bruno carvalho et David Gallay
Date        : 24.02.2020

But         : Test features of class Circle
Remarque(s) :
Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#include <iostream>
#include "../src/color.h"
#include "../src/circle.h"
using namespace std;


int main() {

    Color c(Color::Code::GREEN);

    Circle circle1;
    Circle circle2(5);
    Circle circle3(5, c);
    Circle circle4(c);
    Circle circle5(Color::Code::BLACK);

    cout << circle1 << endl;
    cout << circle2 << endl;
    cout << circle3 << endl;
    cout << circle4 << endl;
    cout << circle5 << endl;

    if(circle1.setRadius(9).getRadius() != 9)
        return EXIT_FAILURE;

    if(circle5.setColor(c).getColor().getColorCode() != c.getColorCode())
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
