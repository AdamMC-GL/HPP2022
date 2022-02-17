#include <stdio.h>
#include <iostream>
#include <string>
#include "autoverhuur.hpp"
using namespace std;

Klant::Klant()
{

}

Klant::Klant(string name)
{
    this->naam = name;
    this->kortingPercentage = kortingPercentage;
}

void Klant::setKorting(double kP){
    kortingPercentage = kP;
}
double Klant::getKorting(){
    return kortingPercentage;
}
string Klant::toString(){
    string str = "op naam van: " + naam + " (korting: " + to_string(kortingPercentage) + "%)\n";
    if(naam == ""){
        return "er is geen huurder bekend\n";
    }
    return str;
}


Auto::Auto()
{

}

Auto::Auto(string Type, double prijsPerDag)
{
    this->Type = Type;
    this->prijsPerDag = prijsPerDag;
}



void Auto::setPrijsPerDag(double prPd){
    prijsPerDag = prPd;
}

double Auto::getPrijsPerDag(){
    return prijsPerDag;
}

string Auto::toString(){
    string str = "autotype: " + Type +" met prijs per dag: " + to_string(prijsPerDag)+"\n";
    if(Type == ""){
        return "er is geen auto bekend\n";
    }
    return str;
}


Autohuur::Autohuur(){

}
Autohuur::Autohuur(Auto autovar, Klant klantvar, int aantalDagen){
    this->aantalDagen = aantalDagen;
    this->autovar = std::move(autovar);
    this->klantvar = std::move(klantvar);
}

void Autohuur::setAantalDagen(int aD){
    aantalDagen = aD;
}
void Autohuur::setGehuurdeAuto(Auto ga){
    autovar = ga;
}
string Autohuur::getGehuurdeAuto() const{
    return autovar.Type + " met prijs per dag: " + to_string(autovar.prijsPerDag) +"%\n";
}
void Autohuur::setHuurder(Klant k){
    klantvar = k;
}
string Autohuur::getHuurder(){
    return klantvar.naam + " met korting van: " + to_string(klantvar.kortingPercentage) + "%\n";
}
double Autohuur::totaalPrijs(){
    double totaalPrijs = aantalDagen * autovar.getPrijsPerDag();
    totaalPrijs = totaalPrijs - (totaalPrijs / 100 * klantvar.getKorting());
    return totaalPrijs;

}
string Autohuur::toString(){
    string str = autovar.toString() + klantvar.toString() + "aantal dagen: " + to_string(aantalDagen) + " en dat kost: " +to_string(totaalPrijs());
    return str;
}


