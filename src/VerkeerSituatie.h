// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#ifndef UNTITLED_VERKEERSITUATIE_H
#define UNTITLED_VERKEERSITUATIE_H
#include "iostream"
#include "map"
#include "vector"
#include "Baan.h"
#include "../tinyxml/tinyxml.h"
using namespace std;


class VerkeerSituatie{
private:
    vector<Baan> Banen; //Aantal banen bijhouden
    int Tijdstip;
public:
    VerkeerSituatie();

    int getSimulatieTijd() const;

    void setSimulatieTijd(int simulatieTijd);

    void addBaan(Baan weg);
    vector<Baan> GetBanen();
    void read(const char *fileName, VerkeerSituatie &verk);
    int getal(string const &Getal);
};



#endif //UNTITLED_VERKEERSITUATIE_H
