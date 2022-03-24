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
    double simTime;
    double Vmax;
    double vertraagfac;
    vector<VerkeersLicht*> Verkeerslichten;
    vector<Voertuig*> Voertuigen;

public:
    // CONSTRUCTOR
    Baan();
    // GETTERS AND SETTERS
    bool properlyInit();
    const string &getNaam();
    void setNaam(const string &name);
    int getLengte();
    void setLengte(int length);
    int getRedLight();
    double getSimTime();
    int getLichtSize();
    int getVoertuigSize();
    void setSimTime(double simTime);
    double getVmax();
    void setVmax(double vmax);
    double getVertraagfac();
    void setVertraagfac(double vertraagfac);
    const vector<VerkeersLicht*> &getVerkeerslichten();
    const vector<Voertuig*> &getVoertuigen();
    void setVerkeerslicht(VerkeersLicht* licht);
    void setVoertuig(Voertuig* motor);
    // ADDED FUNCTIONS
    void PrintVoertuigen();
    void BerekenSnelheid();
    void BerekenVersnellingGroen(bool slowdown);
    void ReduceCycle();
    bool isLightRed();
//    void BerekenVersnellingRood();
    vector<pair<bool,int> > getRedLights();
};



#endif //UNTITLED_BAAN_H
