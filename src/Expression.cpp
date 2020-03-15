#include "Expression.hh"


/*!
 * Realizuje wyswietlanie wyrazenia zespolonego.
 * Argument:
 *    expr - wyrazenie zespolone,
 */
void Display(Expression expr)
{
    switch (expr.op)
    {
    case kAddition:
        cout << expr.arg1 << " + " << expr.arg2;
        break;
    
    case kSubtraction:
        cout << expr.arg1 << " - " << expr.arg2;
        break;

    case kMultiplication:
        cout << expr.arg1 << " * " << expr.arg2;
        break;

    case kDivision:
        cout << expr.arg1 << " / " << expr.arg2;
        break;

    default: 
        cout << "Nieprawidlowy operator" << endl;
        break;
    }
}

/*!
 * Realizuje obliczanie wartosci wyrazenia zespolonego.
 * Argumenty:
 *    expr - wyrazenie zespolone,
 * Zwraca:
 *    wynik dzialania w postaci liczby zespolonej.
 */
Complex Solve(Expression expr)
{
    Complex dupa;
     
    switch (expr.op)
    {
    case kAddition:
        return expr.arg1 + expr.arg2;
        break;
    
    case kSubtraction:
        return expr.arg1 - expr.arg2;
        break;

    case kMultiplication:
        return expr.arg1 * expr.arg2;
        break;

    case kDivision:
        return expr.arg1 / expr.arg2;
        break;

    default: 
        cout << "Nieprawidlowy operator" << endl;
        return dupa;
        break;
    }
}
