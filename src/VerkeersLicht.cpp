// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163

#include "VerkeersLicht.h"
#include "DesignByContract.h"

VerkeersLicht::VerkeersLicht() {
    Color = "green";
    positie = 0.0;
    cyclus = 0;
    Clone = 0;
    isThis = this;
}
bool VerkeersLicht::properlyInitialized(){
    return isThis == this;
}

const string &VerkeersLicht::getBaan() {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    ENSURE(baan.length() != 0, "Baan naam is leeg");
    return baan;
}

void VerkeersLicht::setBaan(const string &bane) {
    VerkeersLicht::baan = bane;
}

double VerkeersLicht::getPositie(){
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    ENSURE(positie > 0, "Positie kan niet negatief zijn");
    return positie;
}

void VerkeersLicht::setPositie(double position) {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    VerkeersLicht::positie = position;
    ENSURE(this->getPositie() == position, "Failed Assertion");
}

int VerkeersLicht::getCyclus() const {
    return cyclus;
}

void VerkeersLicht::setCyclus(int cycl) {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    VerkeersLicht::cyclus = cycl;
    ENSURE(this->getCyclus() == cycl, "Failed Assertion");
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

void VerkeersLicht::switchColor() {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    if (this->Color == "green"){
        this->Color = "red";
    }
    else{
        this->Color = "green";
    }
}

int VerkeersLicht::getClone(){
//    REQUIRE(this->properlyInitialized(), "Not properly initialized");
//    ENSURE(this->getClone() > 0, "Cycle kan niet negatief zijn");
    return Clone;
}


