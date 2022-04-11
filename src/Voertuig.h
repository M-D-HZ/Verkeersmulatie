// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#ifndef UNTITLED_VOERTUIG_H
#define UNTITLED_VOERTUIG_H
#include "iostream"
#include "map"
#include "vector"
#include "Baan.h"
#include<iterator>
#include "cmath"

using namespace std;


class Voertuig{
private:
    string baan;
    double positie;
    int lengte;
    double snelheid;
    double versnelling;
    Voertuig* isThis;
    double Vmax;
    double vmax;
    double vertraagfac;
    double Amax;
    double Bmax;
    int fmin;




public:
    // CONSTRUCTORS
    Voertuig(int lengte);
    // GETTERS AND SETTERS
    double getVersnelling();
    void setVersnelling(double versnelling);
    int getLengte();
    void setLengte(int lengte);
    double getSnelheid();
    void setSnelheid(double snelheid);
    const string &getBaan();
    double getPositie();
    void setBaan(string const &name);
    void setPositie(double number);
    void berekenVersnelling(vector<VerkeersLicht*> Verkeerslichten,Voertuig* even);
    VerkeersLicht* dichtBijzijndeLicht(vector<VerkeersLicht*> Verkeerslichten);
    void BerekenSnelheid(double time);

    //Properly Initialized
    bool properlyInitialized();

};

#endif //UNTITLED_VOERTUIG_H
