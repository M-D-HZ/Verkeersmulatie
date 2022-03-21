// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163

#include "Voertuig.h"


const string &Voertuig::getBaan() {
    return baan;
}

double Voertuig::getPositie() {
    return positie;
}

void Voertuig::setBaan(const string &name) {
    baan = name;
}

void Voertuig::setPositie(double number) {
    positie = number;
}

double Voertuig::getSnelheid() const {
    return snelheid;
}

void Voertuig::setSnelheid(double speed) {
    snelheid = speed;
}

int Voertuig::getLengte() const {
    return lengte;
}

void Voertuig::setLengte(int lengt) {
    Voertuig::lengte = lengt;
}

double Voertuig::getVersnelling() const {
    return versnelling;
}

void Voertuig::setVersnelling(double versnel) {
    versnelling = versnel;
}

Voertuig::Voertuig(int lengte) : lengte(lengte) {
    snelheid = 0;
    versnelling = 0;
}

