// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#ifndef UNTITLED_VERKEERSITUATIE_H
#define UNTITLED_VERKEERSITUATIE_H
#include "iostream"
#include "map"
#include "vector"
#include "Baan.h"
#include "../tinyxml/tinyxml.h"
#include "VoertuigGenerator.h"
using namespace std;


class VerkeerSituatie{
private:
    vector<Baan*> Banen; //Aantal banen bijhouden
    int simulatie;
    int Tijdstip;
    VerkeerSituatie *isThis;
    VoertuigGenerator* generator;
    vector<Voertuig*> voertuigen;
public:
    VerkeerSituatie();
    bool properlyInitialized();
    int getSimulatieTijd();
    void setSimulatieTijd(int simulatieTijd);
    void UpdateBanen(vector<Baan*> baan);
    void addBaan(Baan weg);
    vector<Baan*> GetBanen();
    void GrafischImp();
    void Sorteren();
    void read(const char *fileName);
    int getal(string const &Getal);
    void start();
    bool isleeg();
};



#endif //UNTITLED_VERKEERSITUATIE_H
