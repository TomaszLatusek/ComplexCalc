#include <iostream>

#include "Database.hh"
#include "Statistics.hh"

using namespace std;

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        cout << endl;
        cout << " Brak opcji okreslajacej rodzaj testu." << endl;
        cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
        cout << endl;
        return 1;
    }

    Database base = {nullptr, 0, 0};

    if (Init(&base, argv[1]) == false)
    {
        cerr << " Inicjalizacja testu nie powiodla sie." << endl;
        return 1;
    }

    cout << endl;
    cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
    cout << endl;

    Expression expression;
    Complex answer;
    Statistics stats;
    /* Inicjalizacja */
    stats.correct = stats.max = stats.wrong = 0; 

    while (GetNextQuestion(&base, &expression))
    {
        cout << endl
             << "[?] Podaj wynik operacji: ";
        Display(expression);
        cout << endl;

        cout << "    Twoja odpowiedz: ";
        cin >> answer;

        if (answer == Solve(expression))
        {
            cout << "[+] Odpowiedz poprawna" << endl;
            stats.correct++;
        }
        else
        {
            cout << "[-] Blad. Prawidlowym wynikiem jest: " << Solve(expression) << endl;
            stats.wrong++;
        }
    }

    cout << endl;
    cout << " Koniec testu" << endl;
    cout << endl;
    Show(stats);
}
