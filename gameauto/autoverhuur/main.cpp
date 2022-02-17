#include <stdio.h>
#include <iostream>
#include <string>
#include "autoverhuur.hpp"
using namespace std;


int main()
{
    Klant k = {"Mijnheer de Vries"};
    k.setKorting(10.0);
    Auto a1("Peugeot 207", 50);
    Autohuur ah1 = {a1, k, 4};
    cout << "Eerste autohuur: " << ah1.toString() << endl;
    cout << endl;

    Auto a2 = {"Ferrari", 3500};
    Autohuur ah2 = {a1, k, 10};
    ah2.setGehuurdeAuto(a2);
    ah2.setAantalDagen(1);
    cout << "Tweede autohuur: " << ah2.toString() << endl;
    cout << endl;

    cout << "Gehuurd: " << ah1.getGehuurdeAuto() << endl;
    cout << "Gehuurd: " << ah2.getGehuurdeAuto() << endl;

    return 0;
}