// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163

#include "Voertuig.h"
#include "DesignByContract.h"
#include "VerkeersLicht.h"

// CONSTRUCTORS
Voertuig::Voertuig() {
    snelheid = 0;
    versnelling = 0;
    positie = 0;
    isThis = this;
    Vmax = 0;
    Amax = 0;
    Bmax = 0;
    fmin = 0;
    vertraagfac = 0.4;
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
    for (unsigned int i = 0; i <lichten.size() ; i++) {
        if(this->getPositie() < lichten[i]->getPositie()){
            return lichten[i];
        }
    }
    return NULL;
}

void Voertuig::berekenVersnelling(vector<VerkeersLicht*> Verkeerslichten,Voertuig* even) {
    VerkeersLicht *licht = dichtBijzijndeLicht(Verkeerslichten);
    double lichtafstand = licht->getPositie() - this->getPositie();
    if(licht->getColor()=="red" && lichtafstand<7.5 && even != NULL && even->getPositie()>licht->getPositie() && licht !=NULL ){
        return;
    }
    else if(licht->getColor()=="red" && lichtafstand<15 && even != NULL && even->getPositie()>licht->getPositie() && licht !=NULL ){
        double hel = -((Bmax * snelheid)/vmax);
        this->setVersnelling(hel);
    }
    else if(licht->getColor()=="red" && lichtafstand<50 && even != NULL && even->getPositie()>licht->getPositie() && licht !=NULL){
        this->setVersnelling(Amax * (1-pow(snelheid/vmax,4)));
    }
    else if(even==NULL){
        this->setVersnelling(Amax * (1-pow(snelheid/Vmax,4)));
    }
    else{
        double max = 0;
        double volgafstand = even->getPositie() - this->getPositie() - even->getLengte();
        double snelheidsverchil = this->getSnelheid() - even->getSnelheid();
        if (0 < (snelheid + ((snelheid * snelheidsverchil) / 2 * sqrt(Amax * Bmax)))) {
            max = snelheid + ((snelheid * snelheidsverchil) / 2 * sqrt(Amax * Bmax));
        }
        double delta = (fmin + max) / volgafstand;
        this->setVersnelling(Amax * (1 - pow(snelheid /Vmax, 4) - pow(delta, 2)));
    }
}

void Voertuig::BerekenSnelheid(double time){
    if((snelheid + (versnelling * time))<0){
        positie = (positie-(pow(snelheid,2)/(2*versnelling)));
        snelheid = 0;
    }
    else if ((snelheid + (versnelling*time)) <= Vmax){
        snelheid = (snelheid + (versnelling*time));
        positie = positie + (snelheid*time) + (versnelling * (pow(time,2)/2));
    }
    else{
        positie = positie + (snelheid*time) + (versnelling * (pow(time,2)/2));
    }
}

const string &Voertuig::getType() const {
    return type;
}

void Voertuig::setType(const string &typ) {
    if (typ == "auto"){
        lengte = 4;
        Vmax = 16.6;
        Amax = 1.44;
        Bmax = 4.61;
        fmin = 4;
    }
    else if (typ == "bus"){
        lengte = 12;
        Vmax = 11.4;
        Amax = 1.22;
        Bmax = 4.29;
        fmin = 12;
    }
    else if (typ == "brandweerwagen"){
        lengte = 10;
        Vmax = 14.6;
        Amax = 1.33;
        Bmax = 4.56;
        fmin = 10;
    }
    else if (typ == "ziekenwagen"){
        lengte = 8;
        Vmax = 15.5;
        Amax = 1.44;
        Bmax = 4.47;
        fmin = 8;
    }
    else if (typ == "politiecombi"){
        lengte = 6;
        Vmax = 17.2;
        Amax = 1.55;
        Bmax = 4.92;
        fmin = 6;
    }
    Voertuig::type = typ;
}

string Voertuig::getType() {
    return this->type;
}
