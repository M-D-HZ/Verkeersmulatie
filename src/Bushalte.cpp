//
// Created by othma on 12/04/2022.
//

#include "Bushalte.h"

Bushalte::Bushalte() {}

const string &Bushalte::getBaan() const {
    return baan;
}

void Bushalte::setBaan(const string &b) {
    Bushalte::baan = b;
}

int Bushalte::getPositie() const {
    return positie;
}

void Bushalte::setPositie(int pos) {
    Bushalte::positie = pos;
}

int Bushalte::getWachttijd() const {
    return wachttijd;
}

void Bushalte::setWachttijd(int wacht) {
    Bushalte::wachttijd = wacht;
}
