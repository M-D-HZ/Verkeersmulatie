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
    int positie;
    int lengte;
    double snelheid;
    double versnelling;
public:
    Voertuig(int lengte);
    double getVersnelling() const;
    void setVersnelling(double versnelling);
    int getLengte() const;
    void setLengte(int lengte);
    double getSnelheid() const;
    void setSnelheid(double snelheid);
    const string &getBaan();
    int getPositie();
    void setBaan(string const &name);
    void setPositie(int number);

};

#endif //UNTITLED_VOERTUIG_H
