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
    int positie;
    int cyclus;
public:
    VerkeersLicht();

    const string &getBaan() const;

    void setBaan(const string &baan);

    double getPositie() const;

    void setPositie(double positie);

    void setClone(int clone);

    int getCyclus() const;

    void setCyclus(int cyclus);

};


#endif //UNTITLED_VERKEERSLICHT_H
