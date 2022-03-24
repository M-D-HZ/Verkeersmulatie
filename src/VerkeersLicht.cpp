// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163

#include "VerkeersLicht.h"
#include "DesignByContract.h"


const string &VerkeersLicht::getBaan() const {
    return this->baan;
}

bool VerkeersLicht::properlyInitialized(){
    return isThis == this;
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
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    if (Clone == 0){
        Clone = cyclus;
        switchColor();
        ENSURE(this->getClone() == cyclus, "Failed Assertion");
        return;
    }
    int even = Clone;
    Clone -=1;
    ENSURE(this->getClone() == even-1, "Failed assertion");
}

VerkeersLicht::VerkeersLicht() {
    Color = "green";
    isThis = this;
}

void VerkeersLicht::switchColor() {
    if (this->Color == "green"){
        this->Color = "red";
    }
    else{
        this->Color = "green";
    }
}

int VerkeersLicht::getClone() const {
    return Clone;
}


