// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#ifndef UNTITLED_BAAN_H
#define UNTITLED_BAAN_H

#include "iostream"
#include "map"
#include "vector"
#include "Bushalte.h"
#include "Kruispunt.h"

using namespace std;

class VoertuigGenerator;
class VerkeersLicht;
class Voertuig;// Predeclaring classes before use
class Baan{
private:
    Baan *isThis;
    string naam;
    int lengte;
    VoertuigGenerator* Generator;
    double simTime;
    vector<VerkeersLicht*> Verkeerslichten;
    vector<Voertuig*> Voertuigen;
    vector<Bushalte*> Bushaltes;
    vector<Kruispunt*> Kruispunten;
    int pos;

public:
    // CONSTRUCTOR
    Baan();
    // GETTERS AND SETTERS
    bool properlyInit();
    const string &getNaam();
    void setNaam(const string &name);
    int getLengte();
    void setLengte(int length);
    double getSimTime();
    int getLichtSize();
    int getVoertuigSize();
    void setSimTime(double simTime);
    const vector<VerkeersLicht*> &getVerkeerslichten();
    vector<Voertuig*> getVoertuigen();
    void setVerkeerslicht(VerkeersLicht* licht);
    void setVoertuig(Voertuig* motor);
    void setBushalte(Bushalte* halte);
    void setKruispunt(Kruispunt* kruising);
    VoertuigGenerator* getVoertuigGenerator();
    void setVoertuiggenerator(VoertuigGenerator* generator);
    // ADDED FUNCTIONS
    void Sorteren();
    void PrintVoertuigen(int Tijd);
    void MakeOutput(int Tijd);
    void Snelheid();
    void Versnelling();
    void ReduceCycle();

//    void BerekenVersnellingRood();

};



#endif //UNTITLED_BAAN_H
