// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#ifndef UNTITLED_VOERTUIG_H
#define UNTITLED_VOERTUIG_H
#include "iostream"
#include "map"
#include "vector"
#include "Baan.h"

using namespace std;


class Voertuig{
private:
    string baan;
    double positie;
    int lengte;
    double snelheid;
    double versnelling;
    Voertuig* isThis;
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

    //Properly Initialized
    bool properlyInitialized();

};

#endif //UNTITLED_VOERTUIG_H
