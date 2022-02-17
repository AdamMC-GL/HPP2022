#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Klant {
public:
    string naam;
    double kortingPercentage;

    Klant();
    Klant(string name);
    void setKorting(double kP);
    double getKorting();
    string toString();
};

class Auto {

public:

    string Type;
    double prijsPerDag;

    Auto();
    Auto(string Type, double prijsPerDag);
    void setPrijsPerDag(double prPd);
    double getPrijsPerDag();
    string toString();
};


class Autohuur{
public:
    Auto autovar;
    Klant klantvar;
    int aantalDagen;

    Autohuur();
    Autohuur(Auto autovar, Klant klantvar, int aantalDagen);
    void setAantalDagen(int aD);
    void setGehuurdeAuto(Auto ga);
    string getGehuurdeAuto() const;
    void setHuurder(Klant k);
    string getHuurder();
    double totaalPrijs();
    string toString();
};
