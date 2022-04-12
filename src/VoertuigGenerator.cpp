// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163

#include "VoertuigGenerator.h"

VoertuigGenerator::VoertuigGenerator() {}

Voertuig* VoertuigGenerator::NewVoertuig(const string &b, double lengte) {
    Voertuig* New = new Voertuig(lengte);
    New->setBaan(b);
    New->setPositie(0);
    New->setLengte(lengte);
    return New;
}


