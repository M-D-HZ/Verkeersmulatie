// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#include "Baan.h"
#include "Voertuig.h"
#include "VerkeersLicht.h"
#include "iostream"
#include "string"
#include "cmath"
#include "DesignByContract.h"

using namespace std;
// CONSTRUCTORS
Baan::Baan() {
    simTime = 0.0166;
    Vmax = 16.6;
    vertraagfac = 0.4;
    Amax = 1.44;
    Bmax = 4.61;
    fmin = 4;
    lengte = 0;
    vmax = vertraagfac*Vmax;
    isThis = this;
}
bool Baan::properlyInit(){
    return isThis == this;
}
// GETTERS AND SETTERS
double Baan::getSimTime(){
    REQUIRE(this->properlyInit(), "Not properly initialized");
    ENSURE(simTime >= 0, "Simulation time is negatief");
    return simTime;
}

double Baan::getVmax(){
    REQUIRE(this->properlyInit(), "Not properly initialized");
    ENSURE(Vmax >= 0, "Vmax is negatief");
    return Vmax;
}

const string &Baan::getNaam() const {
    return naam;
}

void Baan::setNaam(const string &name) {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    ENSURE(name.length() != 0, "Naam is leeg");
    Baan::naam = name;
}

int Baan::getLengte() {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    ENSURE(lengte != 0, "Baan heeft geen lengte");
    return lengte;
}

void Baan::setSimTime(double siTime) {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    Baan::simTime = siTime;
    ENSURE(this->getSimTime() == siTime, "Failed assertion");
}

void Baan::setVmax(double kvmax) {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    Vmax = kvmax;
    ENSURE(this->getVmax() == kvmax, "Failed assertion");
}

void Baan::setLengte(int length) {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    Baan::lengte = length;
    ENSURE(this->getLengte() == length, "Failed assertion");
}

void Baan::setVertraagfac(double vertragfac) {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    Baan::vertraagfac = vertragfac;
    ENSURE(this->getVertraagfac() == vertragfac, "Failed assertion");
}

void Baan::setVerkeerslicht(VerkeersLicht* licht) {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    for (unsigned int i = 0; i < unsigned(Verkeerslichten.size()); i++) {
        if (Verkeerslichten[i]->getPositie() == licht->getPositie()) {
            ENSURE(Verkeerslichten[i]->getPositie() == licht->getPositie(), "Failed assertion");
            cout << "Verkeerslicht niet geplaatst, Er staat al een verkeerslicht op deze positie" << endl;
            return;
        }
    }
    Verkeerslichten.push_back(licht);
//    ENSURE(Verkeerslichten.back() == *licht, "Failed assertion");
}

void Baan::setVoertuig(Voertuig* motor) {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()); i++) {
        if (Voertuigen[i]->getPositie() == motor->getPositie()){
            cout << "Voertuig niet geplaatst, Er staat al een voertuig op deze positie" << endl;
            return;
        }
    }
    Voertuigen.push_back(motor);
}

// ADDED FUNCTIONS
void Baan::PrintVoertuigen() {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    REQUIRE(!this->Voertuigen.empty(), "Nothing to print");
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()) ; ++i) {
        cout << "Baan: "<< Voertuigen[i]->getBaan() << endl;
        cout << "---> Positie: "<< Voertuigen[i]->getPositie() << endl;
        cout << "---> Snelheid: " << Voertuigen[i]->getSnelheid() << endl;
        cout << "---> Versnelling: " <<  Voertuigen[i]->getVersnelling()<<endl;
    }
}

void Baan::BerekenVersnellingGroen(bool slowdown) {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    double volgafstand = 0;
    double snelheidsverchil = 0;
    double delta = 0;
    double max = 0;
    double pos = 500;
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()) ; i++) {
        volgafstand = pos - Voertuigen[i]->getPositie();
        if(slowdown && i == 0 && volgafstand < 15){
            cout << "!!--> RED LIGHT <--!!" << endl;
            double hel = -((Bmax*Voertuigen[i]->getSnelheid())/Vmax);
            Voertuigen[i]->setVersnelling(hel);
            ENSURE(Voertuigen[i]->getVersnelling() < 0,"Het moet vertragen");
        }
        else if (slowdown && i == 0 && volgafstand < 50){
            cout << "!!--> RED LIGHT <--!!" << endl;
            double k = Voertuigen[i]->getVersnelling();
            Voertuigen[i]->setVersnelling(Amax * (1-pow(Voertuigen[i]->getSnelheid()/vmax,4)));
            continue;
        }
        else if (i == 0){
            Voertuigen[i]->setVersnelling(Amax * (1-pow(Voertuigen[i]->getSnelheid()/Vmax,4)));
            ENSURE((Voertuigen[i]->getVersnelling() > 0) && (delta ==0),"Het moet versnellen");
            continue;
        }
        else{
            volgafstand = Voertuigen[i-1]->getPositie() - Voertuigen[i]->getPositie() - Voertuigen[i-1]->getLengte();
            if(slowdown || volgafstand <= fmin){
                volgafstand = Voertuigen[i-1]->getPositie() - Voertuigen[i]->getPositie() - Voertuigen[i-1]->getLengte();
                snelheidsverchil = Voertuigen[i]->getSnelheid() - Voertuigen[i-1]->getSnelheid();
                if (0 < (Voertuigen[i]->getSnelheid()+((Voertuigen[i]->getSnelheid() * snelheidsverchil)/2*sqrt(Amax*Bmax)))){
                    max =Voertuigen[i]->getSnelheid()+((Voertuigen[i]->getSnelheid()*snelheidsverchil)/2*sqrt(Amax*Bmax));
                }
                delta = (fmin + max)/volgafstand;
                Voertuigen[i]->setVersnelling(Amax * (1-pow(Voertuigen[i]->getSnelheid()/Vmax,4) - pow(delta,2)));
            }
            else{
                volgafstand = Voertuigen[i-1]->getPositie() - Voertuigen[i]->getPositie() - Voertuigen[i-1]->getLengte();
                snelheidsverchil = Voertuigen[i]->getSnelheid() - Voertuigen[i-1]->getSnelheid();
                if (0 < (Voertuigen[i]->getSnelheid()+((Voertuigen[i]->getSnelheid() * snelheidsverchil)/2*sqrt(Amax*Bmax)))){
                    max =Voertuigen[i]->getSnelheid()+((Voertuigen[i]->getSnelheid()*snelheidsverchil)/2*sqrt(Amax*Bmax));
                }
                delta = (fmin + max)/volgafstand;
                Voertuigen[i]->setVersnelling(Amax * (1-pow(Voertuigen[i]->getSnelheid()/Vmax,4) - pow(delta,2)));
//            ENSURE(Voertuigen[i]->getVersnelling() > 0,"Het moet versnellen");
            }
        }
    }
}

void Baan::BerekenSnelheid() {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    REQUIRE(!this->Voertuigen.empty(), "Voertuigen bestaan niet");
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()) ; i++) {
        if (Voertuigen[i]->getPositie() > this->lengte){
            Voertuigen.erase(Voertuigen.begin());
        }
        else if (Voertuigen[i]->getSnelheid() + (Voertuigen[i]->getVersnelling()*simTime) < 0){
            double check = Voertuigen[i]->getPositie()-(pow(Voertuigen[i]->getSnelheid(),2)/(2*Voertuigen[i]->getVersnelling()));
            Voertuigen[i]->setPositie(Voertuigen[i]->getPositie()-(pow(Voertuigen[i]->getSnelheid(),2)/(2*Voertuigen[i]->getVersnelling())));
            ENSURE(Voertuigen[i]->getPositie() == check, "Failed assertion");
        }
        else if (Voertuigen[i]->getSnelheid() + (Voertuigen[i]->getVersnelling()*simTime) <= Vmax){
            Voertuigen[i]->setSnelheid(Voertuigen[i]->getSnelheid() + (Voertuigen[i]->getVersnelling()*simTime));
            double even = Voertuigen[i]->getPositie() + (Voertuigen[i]->getSnelheid()*simTime) + (Voertuigen[i]->getVersnelling() * (pow(simTime,2)/2));
            Voertuigen[i]->setPositie(even);
            ENSURE(Voertuigen[i]->getPositie() == even, "Failed assertion");
        }
        else{
            double even = Voertuigen[i]->getPositie() + (Voertuigen[i]->getSnelheid()*simTime) + (Voertuigen[i]->getVersnelling() * (pow(simTime,2)/2));
            Voertuigen[i]->setPositie(even);
            ENSURE(Voertuigen[i]->getPositie() == even, "Failed Assertion");
        }
    }
}

void Baan::ReduceCycle() {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    REQUIRE(!this->Verkeerslichten.empty(), "Verkeerslichten bestaan niet");
    for (unsigned int i = 0; i < Verkeerslichten.size(); i++) {
        Verkeerslichten[i]->reduce();
    }
}

bool Baan::isLightRed() {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    for (unsigned int i = 0; i < Verkeerslichten.size(); ++i) {
        if (Verkeerslichten[i]->getColor() == "red"){
            return true;
        }
    }
    return false;
}

vector<pair<bool,int> > Baan::getRedLights(){
    REQUIRE(this->properlyInit(), "Not properly initialized");
    vector<pair<bool,int> > lights;
    for (unsigned int i = 0; i < Verkeerslichten.size(); ++i) {
        if (Verkeerslichten[i]->getColor() == "red"){
            int even = lights.size();
            lights.push_back(make_pair(true,Verkeerslichten[i]->getPositie()));
            ENSURE(unsigned(lights.size()) == unsigned(even+1),"Er moet lichten worden toegevoegd");
        }
    }
    ENSURE(!lights.empty(),"Het mag niet leeg zijn");
    return lights;
}



// GARBAGE FUNCTIONS WE MIGHT USE AGAIN
//void Baan::BerekenVersnellingRood(double LightPos){
//    for (unsigned int i = 0; i < unsigned(Voertuigen.size()) ; i++) {
//        if(i==0 && Voertuigen[i].getPositie() < LightPos - 50){
//            Voertuigen[i].setVersnelling(-(4.61 * Voertuigen[i].getSnelheid())/(0.4*16.6));
//        }
//        else{
//            Voertuigen[i].setVersnelling(-(4.61 * Voertuigen[i].getSnelheid())/16.6);
//        }
//    }
//}



