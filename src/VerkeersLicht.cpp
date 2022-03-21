// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163

#include "VerkeersLicht.h"


const string &VerkeersLicht::getBaan() const {
    return baan;
}

void VerkeersLicht::setBaan(const string &bane) {
    VerkeersLicht::baan = bane;
}

double VerkeersLicht::getPositie() const {
    return positie;
}

void VerkeersLicht::setPositie(double position) {
    VerkeersLicht::positie = position;
}

int VerkeersLicht::getCyclus() const {
    return cyclus;
}

void VerkeersLicht::setCyclus(int cycl) {
    VerkeersLicht::cyclus = cycl;
}

void VerkeersLicht::reduce(){
    if (Clone == 0){
        Clone = cyclus;
        switchColor();
        return;
    }
     Clone -=1;
}

VerkeersLicht::VerkeersLicht() {
    Color = "green";
}

void VerkeersLicht::switchColor() {
    if (this->Color == "green"){
        this->Color = "red";
    }
    else{
        this->Color = "green";
    }
}

string VerkeersLicht::getColor(){
    return Color;
}

void VerkeersLicht::setClone(int clone) {
    Clone = clone;
}
