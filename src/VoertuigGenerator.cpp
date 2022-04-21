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

const string &VoertuigGenerator::getBaan() const {
    return baan;
}

void VoertuigGenerator::setBaan(const string &b) {
    VoertuigGenerator::baan = b;
}

const string &VoertuigGenerator::getType() const {
    return type;
}

void VoertuigGenerator::setType(const string &ty) {
    VoertuigGenerator::type = ty;
}

int VoertuigGenerator::getFrequentie() const {
    return frequentie;
}

void VoertuigGenerator::setFrequentie(int freq) {
    VoertuigGenerator::frequentie = freq;
}


