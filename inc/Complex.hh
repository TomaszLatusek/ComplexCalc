#pragma once
#include <iostream>

using namespace std;
/*!
 *  Plik zawiera definicje struktury Complex oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct Complex
{
    double re; /*! Pole repezentuje czesc rzeczywista. */
    double im; /*! Pole repezentuje czesc urojona. */
};

/*
 * Zapowiedzi definicji przeciazen operatorow
 */
Complex operator+(Complex arg1, Complex arg2);
Complex operator-(Complex arg1, Complex arg2);
Complex operator*(Complex arg1, Complex arg2);
Complex operator/(Complex arg1, Complex arg2);
ostream& operator<<(ostream& os,Complex c);
istream& operator>>(istream& os,Complex& c);
bool operator==(Complex arg1, Complex arg2);


void ShowAlert(istream& is, int i);