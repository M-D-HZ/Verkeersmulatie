//
// Created by othma on 21/04/2022.
//

#include "Kruispunt.h"

Kruispunt::Kruispunt() {}

const pair<Baan *, int> &Kruispunt::getPunt1() const {
    return Punt1;
}

void Kruispunt::setPunt1(const pair<Baan *, int> &punt1) {
    Punt1 = punt1;
}

const pair<Baan *, int> &Kruispunt::getPunt2() const {
    return Punt2;
}

void Kruispunt::setPunt2(const pair<Baan *, int> &punt2) {
    Punt2 = punt2;
}
