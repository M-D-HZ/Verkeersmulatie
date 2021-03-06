// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163

#include "VerkeersLicht.h"
#include "DesignByContract.h"

VerkeersLicht::VerkeersLicht() {
    Color = "green";
    positie = 0;
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

string VerkeersLicht::getColor(){
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    ENSURE(Color.length() != 0, "kleur is leeg");
    return Color;
}

int VerkeersLicht::getPositie(){
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    ENSURE(positie > 0, "Positie kan niet negatief zijn");
    return positie;
}

int VerkeersLicht::getCyclus() {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    ENSURE(cyclus > 0, "Cyclus kan niet negatief zijn");
    return cyclus;
}

void VerkeersLicht::setBaan(const string &bane) {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    VerkeersLicht::baan = bane;
    ENSURE(this->getBaan() == bane, "Failed Assertion");
}

void VerkeersLicht::setPositie(int position) {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    VerkeersLicht::positie = position;
    ENSURE(this->getPositie() == position, "Failed Assertion");
}

void VerkeersLicht::setCyclus(int cycl) {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    VerkeersLicht::cyclus = cycl;
    ENSURE(this->getCyclus() == cycl, "Failed Assertion");
}

void VerkeersLicht::setClone(int clone) {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    Clone = clone;
    ENSURE(this->getClone() == clone, "Failed Assertion");
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
        cout << "!!--> REDLIGHT <--!!" << endl<<endl;
    }
    else{
        this->Color = "green";
        cout << "!!--> GREENLIGHT <--!!" << endl<<endl;
    }
}

int VerkeersLicht::getClone(){
//    REQUIRE(this->properlyInitialized(), "Not properly initialized");
//    ENSURE(this->getClone() > 0, "Cycle kan niet negatief zijn");
    return Clone;
}


