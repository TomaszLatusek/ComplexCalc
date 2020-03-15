#include "Complex.hh"
#include <iostream>
#include <limits>

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy skladnik dodawania,
 *    arg2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
Complex operator+(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = arg1.re + arg2.re;
    result.im = arg1.im + arg2.im;
    return result;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy skladnik odejmowania,
 *    arg2 - drugi skladnik odejmowania.
 * Zwraca:
 *    roznice dwoch skladnikow przekazanych jako parametry.
 */
Complex operator-(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = arg1.re - arg2.re;
    result.im = arg1.im - arg2.im;
    return result;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy skladnik mnozenia,
 *    arg2 - drugi skladnik mnozenia.
 * Zwraca:
 *    iloczyn dwoch skladnikow przekazanych jako parametry.
 */
Complex operator*(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = (arg1.re * arg2.re) - (arg1.im * arg2.im);
    result.im = (arg1.im * arg2.re) + (arg1.re * arg2.im);
    return result;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    arg1 - pierwszy skladnik dzielenia,
 *    arg2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
Complex operator/(Complex arg1, Complex arg2)
{
    Complex result;

    result.re = ((arg1.re * arg2.re) + (arg1.im * arg2.im)) / ((arg2.re * arg2.re) + (arg2.im * arg2.im));
    result.im = ((arg1.im * arg2.re) - (arg1.re * arg2.im)) / ((arg2.re * arg2.re) + (arg2.im * arg2.im));
    return result;
}

/* Complex conjugate(Complex c)
{
    Complex result;

    result.re = c.re;
    result.im = -c.im;

    return result;
}
 */

bool operator==(Complex arg1, Complex arg2)
{
    if (arg1.re == arg2.re && arg1.im == arg2.im)
        return true;
    else
        return false;
}

/*!Display
 * Realizuje wyswietlnie liczby zespolonej na ekranie.
 * Argumenty:
 *    os - output stream,
 *    c - liczba zesppolona.
 * Zwraca:
 *    wyswietla liczbe c na ekranie.
 */
ostream &operator<<(ostream &os, Complex c)
{
    os << "(" << c.re << showpos << c.im << noshowpos << "i)";
    return os;
}

/*!
 * Realizuje wczytywanie liczby zespolonej.
 * Argumenty:
 *    is - intput stream,
 *    c - liczba zesppolona.
 * Zwraca:
 *    wczytuje z klawiatury liczbe c.
 */
istream &operator>>(istream &is, Complex &c)
{
    int i = 0;
    char ch[4];

    while (i <= 3) /* 3 proby poprwnego wpisania liczby */
    {

        is >> ch[0];
        if (ch[0] != '(')
        {
            is.ignore(32767, '\n');
            if (i < 3)
            {
                cout << endl
                     << "[!] Blad zapisu liczby zespolonej." << endl;
                cout << "    Sprobuj jeszcze raz: ";
            }
            i++;
            continue;
        }

        is >> c.re;
        if (is.fail())
        {
            is.clear();
            is.ignore(32767, '\n');
            if (i < 3)
            {
                cout << endl
                     << "[!] Blad zapisu liczby zespolonej." << endl;
                cout << "    Sprobuj jeszcze raz: ";
            }
            i++;
            continue;
        }

        is >> ch[1];
        if (ch[1] != '+' && ch[1] != '-')
        {
            is.ignore(32767, '\n');
            if (i < 3)
            {
                cout << endl
                     << "[!] Blad zapisu liczby zespolonej." << endl;
                cout << "    Sprobuj jeszcze raz: ";
            }
            i++;
            continue;
        }

        is >> c.im;
        if (is.fail())
        {
            is.clear();
            is.ignore(32767, '\n');
            if (i < 3)
            {
                cout << endl
                     << "[!] Blad zapisu liczby zespolonej." << endl;
                cout << "    Sprobuj jeszcze raz: ";
            }
            i++;
            continue;
        }
        else if (ch[1] == '-')
        {
            c.im *= -1;
        }

        is >> ch[2];
        if (ch[2] != 'i')
        {
            is.ignore(32767, '\n');
            if (i < 3)
            {
                cout << endl
                     << "[!] Blad zapisu liczby zespolonej." << endl;
                cout << "    Sprobuj jeszcze raz: ";
            }
            i++;
            continue;
        }

        is >> ch[3];
        if (ch[3] != ')')
        {
            is.ignore(32767, '\n');
            if (i < 3)
            {
                cout << endl
                     << "[!] Blad zapisu liczby zespolonej." << endl;
                cout << "    Sprobuj jeszcze raz: ";
            }
            i++;

            continue;
        }
        else
            return is;
    }

    return is;
}
