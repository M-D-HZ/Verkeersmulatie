//
// Created by othma on 12/04/2022.
//

#include "Bushalte.h"

Bushalte::Bushalte() {}

const string &Bushalte::getBaan() const {
    return baan;
}

void Bushalte::setBaan(const string &baan) {
    Bushalte::baan = baan;
}

int Bushalte::getPositie() const {
    return positie;
}

void Bushalte::setPositie(int positie) {
    Bushalte::positie = positie;
}

int Bushalte::getWachttijd() const {
    return wachttijd;
}

void Bushalte::setWachttijd(int wachttijd) {
    Bushalte::wachttijd = wachttijd;
}
