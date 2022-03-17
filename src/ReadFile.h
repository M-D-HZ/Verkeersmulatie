// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#ifndef UNTITLED_READFILE_H
#define UNTITLED_READFILE_H
#include <iostream>
#include "../tinyxml/tinyxml.h"
#include "Baan.h"
#include "VerkeersLicht.h"
#include "Voertuig.h"
#include "VoertuigGenerator.h"
#include "VerkeerSituatie.h"

using namespace std;

class ReadFile {
    TiXmlElement* file;
    vector<Baan*> Info;
    Baan bane;
    Voertuig VT;
    VoertuigGenerator voertuigGenerator;
    VerkeersLicht Ligt;
public:
    void read(const char *fileName, VerkeerSituatie* verkeer);
    void setVars(TiXmlElement* verkeer, const string &Type, VerkeerSituatie* verk);
    int getal(string const &Getal);
};


#endif //UNTITLED_READFILE_H
