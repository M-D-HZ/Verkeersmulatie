

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


const string &Baan::getNaam(){
    REQUIRE(this->properlyInit(), "Not properly initialized");
    ENSURE(naam.length() != 0, "Naam is leeg");
    return naam;
}

const vector<Voertuig*> &Baan::getVoertuigen(){
    REQUIRE(this->properlyInit(), "Not properly initialized");
    ENSURE(!Voertuigen.empty(), "er zijn geen voertuigen");
    return Voertuigen;
}


int Baan::getLichtSize() {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    return Verkeerslichten.size();
}

int Baan::getVoertuigSize(){
    return Voertuigen.size();
}


const vector<VerkeersLicht*> &Baan::getVerkeerslichten() {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    ENSURE(!Verkeerslichten.empty(), "Er zijn geen verkeerslichten");
    return Verkeerslichten;
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


void Baan::setLengte(int length) {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    Baan::lengte = length;
    ENSURE(this->getLengte() == length, "Failed assertion");
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

void Baan::Versnelling() {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    pos = Verkeerslichten[0]->getPositie();
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()) ; i++) {
        if (Voertuigen[i]->getPositie() > this->lengte){
            Voertuigen.erase(Voertuigen.begin());
            continue;
        }
        if(i==0){
            Voertuigen[i]->berekenVersnelling(Verkeerslichten,NULL);
        }
        else{
            Voertuigen[i]->berekenVersnelling(Verkeerslichten,Voertuigen[i-1]);
        }
    }
}

void Baan::Snelheid() {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    REQUIRE(!this->Voertuigen.empty(), "Voertuigen bestaan niet");
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()) ; i++) {
        if (Voertuigen[i]->getPositie() > this->lengte){
            Voertuigen.erase(Voertuigen.begin());
        }
        else{
            Voertuigen[i]->BerekenSnelheid(simTime);
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



