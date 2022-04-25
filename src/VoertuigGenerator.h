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
    string type;
    int frequentie;
public:
    VoertuigGenerator();
    Voertuig* NewVoertuig(int tijd, bool leeg);

    const string &getBaan() const;

    void setBaan(const string &b);

    const string &getType() const;

    void setType(const string &ty);

    int getFrequentie() const;

    void setFrequentie(int freq);

};

#endif //UNTITLED_VOERTUIGGENERATOR_H
