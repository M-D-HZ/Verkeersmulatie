// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163

#include "VoertuigGenerator.h"

VoertuigGenerator::VoertuigGenerator() {}

Voertuig* VoertuigGenerator::NewVoertuig() {
    Voertuig* New = new Voertuig();
    New->setBaan(baan);
    New->setPositie(0);
    New->setType(type);
    return New;
}


