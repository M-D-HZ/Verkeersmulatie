// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#ifndef UNTITLED_VERKEERSLICHT_H
#define UNTITLED_VERKEERSLICHT_H
#include "iostream"
#include "map"
#include "vector"
#include "Baan.h"


using namespace std;

class VerkeersLicht{
private:
    string baan;
    double positie;
    int cyclus;
    int Clone;
    string Color;
    VerkeersLicht* isThis;
public:
    //CONSTRUCTOR
    VerkeersLicht();

    //GETTERS
    const string &getBaan();
    double getPositie();
    int getCyclus() ;
    string getColor();

    int getClone();

    //SETTERS
    void setBaan(const string &baan);
    void setPositie(double positie);
    void setClone(int clone);
    void setCyclus(int cyclus);
    //
    void reduce();
    bool properlyInitialized();
    bool RedLight(vector<VerkeersLicht*> Verkeerslichten);

    //KLEUR VERANDERING
    void switchColor();


};


#endif //UNTITLED_VERKEERSLICHT_H
