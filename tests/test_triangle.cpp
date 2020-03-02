/*
-----------------------------------------------------------------------------------
Laboratoire : labo_02
Fichier     : test_triangle.cpp
Auteur(s)   : Bruno carvalho et David Gallay
Date        : 24.02.2020

But         : Test features of class Triangle
Remarque(s) :
Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/

#include <iostream>
#include "../src/color.h"
#include "../src/triangle.h"
using namespace std;


int main() {

    Color c(Color::Code::GREEN);

    Triangle triangle1;
    Triangle triangle2(3, 5);
    Triangle triangle3(3, 4, c);
    Triangle triangle4(c);
    Triangle triangle5(Color::Code::BLUE);

    cout << triangle1 << endl;
    cout << triangle2 << endl;
    cout << triangle3 << endl;
    cout << triangle4 << endl;
    cout << triangle5 << endl;

    if(triangle1.setBase(9).getBase() != 9)
        return EXIT_FAILURE;

    if(triangle4.setHeight(5).getHeight() != 5)
        return EXIT_FAILURE;

    if(triangle5.setColor(c).getColor().getColorCode() != c.getColorCode())
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
