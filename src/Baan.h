// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#ifndef UNTITLED_BAAN_H
#define UNTITLED_BAAN_H

#include "iostream"
#include "map"
#include "vector"

using namespace std;
class VerkeersLicht;
class Voertuig;// Predeclaring classes before use
class Baan{
private:
    string naam;
    int lengte;
    vector<VerkeersLicht> Verkeerslichten;
    vector<Voertuig> Voertuigen;

public:
    Baan();
    const vector<VerkeersLicht> &getVerkeerslichten() const;
    const vector<Voertuig> &getVoertuigen() const;
    const string &getNaam() const;
    void setNaam(const string &name);
    int getLengte() const;
    void setLengte(int length);
    void setVerkeerslicht(VerkeersLicht* licht);
    void setVoertuig(Voertuig* motor);
    void PrintVoertuigen();
    void BerekenSnelheid();
    void BerekenVersnellingGroen();
    void BerekenVersnellingRood(double pos);
    bool isEmpty();
};



#endif //UNTITLED_BAAN_H
