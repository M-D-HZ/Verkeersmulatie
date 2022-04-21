// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#ifndef UNTITLED_BAAN_H
#define UNTITLED_BAAN_H

#include "iostream"
#include "map"
#include "vector"
#include "Bushalte.h"


using namespace std;
class VoertuigGenerator;
class VerkeersLicht;
class Voertuig;// Predeclaring classes before use
class Baan{
private:
    Baan *isThis;
    string naam;
    int lengte;
    double simTime;
    vector<VerkeersLicht*> Verkeerslichten;
    vector<Voertuig*> Voertuigen;
    vector<Bushalte*> Bushaltes;
    vector<pair<Baan*,int> > Kruispunten;
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
    double getVmax();
    void setVmax(double vmax);
    double getVertraagfac();
    void setVertraagfac(double vertraagfac);
    const vector<VerkeersLicht*> &getVerkeerslichten();
    vector<Voertuig*> getVoertuigen();
    void setVerkeerslicht(VerkeersLicht* licht);
    void setVoertuig(Voertuig* motor);
    void setBushalte(Bushalte* halte);
    void setKruispunt(Baan* kruis, int pos);
    // ADDED FUNCTIONS
    void PrintVoertuigen();
    void Snelheid();
    void Versnelling();
    void ReduceCycle();

//    void BerekenVersnellingRood();

};



#endif //UNTITLED_BAAN_H
