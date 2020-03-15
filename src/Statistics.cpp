#include <iostream>
#include "Statistics.hh"

using namespace std;

void Show( Statistics  stats )
{
    stats.max = stats.correct + stats.wrong;
    
    cout << " Statystyki:" << endl;
    cout << endl;
    cout << "Ilosc dobrych odpowiedzi: " << stats.correct << endl;
    cout << "Ilosc blednych odpowiedzi: " << stats.wrong << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: " << (stats.correct / stats.max * 100) << "%" << endl;
}
