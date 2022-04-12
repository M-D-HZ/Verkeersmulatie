// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#ifndef UNTITLED_VOERTUIGGENERATOR_H
#define UNTITLED_VOERTUIGGENERATOR_H
#include "iostream"
#include "map"
#include "vector"
#include "Voertuig.h"

using namespace std;

class VoertuigGenerator{
private:
    string baan;
    int frequentie;
public:
    VoertuigGenerator();
    Voertuig* NewVoertuig(const string &b, double lengte);
};

#endif //UNTITLED_VOERTUIGGENERATOR_H
