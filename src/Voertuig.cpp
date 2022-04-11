// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163

#include "Voertuig.h"
#include "DesignByContract.h"

// CONSTRUCTORS
Voertuig::Voertuig(int lengte) : lengte(lengte) {
    snelheid = 0;
    versnelling = 0;
    positie = 0;
    isThis = this;
    Vmax = 16.6;
    vertraagfac = 0.4;
    Amax = 1.44;
    Bmax = 4.61;
    fmin = 4;
    vmax = vertraagfac*Vmax;
}
bool Voertuig::properlyInitialized(){
    return isThis == this;
}

// GETTERS AND SETTERS
const string &Voertuig::getBaan() {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    ENSURE(baan.length() != 0, "Naam is leeg");
    return baan;
}

double Voertuig::getPositie() {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    ENSURE(positie >= 0, "Positie is negatief");
    return positie;
}

void Voertuig::setBaan(const string &name) {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    baan = name;
    ENSURE(this->getBaan() == name, "Failed Assertion");
}

void Voertuig::setPositie(double number) {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    positie = number;
    ENSURE(this->getPositie() == number, "Failed Assertion");
}

double Voertuig::getSnelheid(){
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    return snelheid;
}

void Voertuig::setSnelheid(double speed) {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    snelheid = speed;
    ENSURE(this->getSnelheid() == speed, "Failed Assertion");
}

int Voertuig::getLengte(){
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    ENSURE(lengte > 0, "Lengte is negatief");
    return lengte;
}

void Voertuig::setLengte(int lengt) {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    Voertuig::lengte = lengt;
    ENSURE(this->getLengte() == lengt, "Failed Assertion");
}

double Voertuig::getVersnelling(){
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    return versnelling;
}

void Voertuig::setVersnelling(double versnel) {
    REQUIRE(this->properlyInitialized(), "Not properly initialized");
    versnelling = versnel;
    ENSURE(this->getVersnelling() == versnel, "Failed Assertion");
}

VerkeersLicht* Voertuig::dichtBijzijndeLicht(vector<VerkeersLicht*> lichten){
    for (int i = 0; i <lichten.size() ; i++) {
        if(this->getPositie() < lichten[i]->getPositie()){
            return lichten[i];
        }
    }
    return NULL;
}

void Voertuig::berekenVersnelling(vector<VerkeersLicht*> Verkeerslichten,int voertuigPos) {
    VerkeersLicht* licht = dichtBijzijndeLicht(Verkeerslichten);
    double lichtafstand = licht->getPositie() - this->getPositie();
    if(licht->getColor()=="Rood" && lichtafstand<15){
        double hel = -((Bmax * snelheid)/vmax);
        this->setVersnelling(hel);
    }
    else if(licht->getColor()=="Rood" && lichtafstand<50){
        this->setVersnelling(Amax * (1-pow(snelheid/vmax,4)));
    }
    else{
        this->setVersnelling(Amax * (1-pow(snelheid/Vmax,4)));
    }
}

void Voertuig::berekenversnelling(vector<VerkeersLicht*> Verkeerslichten,Voertuig* even) {
    VerkeersLicht *licht = dichtBijzijndeLicht(Verkeerslichten);
    double lichtafstand = licht->getPositie() - this->getPositie();
    if(licht->getColor()=="Rood" && lichtafstand<15){
        double hel = -((Bmax * snelheid)/vmax);
        this->setVersnelling(hel);
    }
    else if(licht->getColor()=="Rood" && lichtafstand<50){
        this->setVersnelling(Amax * (1-pow(snelheid/vmax,4)));
    }
    else{
        double volgafstand = even->getPositie() - this->getPositie() - even->getLengte();
        double max = 0;
        double snelheidsverchil = this->getSnelheid() - even->getSnelheid();
        if (0 < (snelheid + ((snelheid * snelheidsverchil) / 2 * sqrt(Amax * Bmax)))) {
            max = snelheid + ((snelheid * snelheidsverchil) / 2 * sqrt(Amax * Bmax));
        }
        double delta = (fmin + max) / volgafstand;
        this->setVersnelling(Amax * (1 - pow(snelheid /Vmax, 4) - pow(delta, 2)));
    }


}