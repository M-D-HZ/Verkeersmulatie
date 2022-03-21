// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#include "Baan.h"
#include "Voertuig.h"
#include "VerkeersLicht.h"
#include "iostream"
#include "string"
#include "cmath"

using namespace std;
Baan::Baan() {}

const string &Baan::getNaam() const {
    return naam;
}

void Baan::setNaam(const string &name) {
    Baan::naam = name;
}

int Baan::getLengte() const {
    return lengte;
}

void Baan::setLengte(int length) {
    Baan::lengte = length;
}

void Baan::setVerkeerslicht(VerkeersLicht* licht) {
    for (unsigned int i = 0; i < unsigned(Verkeerslichten.size()); i++) {
        if (Verkeerslichten[i].getPositie() == licht->getPositie()) {
            cout << "Verkeerslicht niet geplaatst, Er staat al een verkeerslicht op deze positie" << endl;
            return;
        }
    }
    Verkeerslichten.push_back(*licht);
}

void Baan::setVoertuig(Voertuig* motor) {
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()); i++) {
        if (Voertuigen[i].getPositie() == motor->getPositie()){
            cout << "Voertuig niet geplaatst, Er staat al een voertuig op deze positie" << endl;
            return;
        }
    }
    Voertuigen.push_back(*motor);
}

bool Baan::isEmpty() {
    if(Voertuigen.empty()){
        return true;
    }
    return false;
}

const vector<VerkeersLicht> &Baan::getVerkeerslichten() const {
    return Verkeerslichten;
}

const vector<Voertuig> &Baan::getVoertuigen() const {
    return Voertuigen;
}

void Baan::PrintVoertuigen() {
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()) ; ++i) {
        cout << "Baan: "<< Voertuigen[i].getBaan() << endl;
        cout << "Positie: "<< Voertuigen[i].getPositie() << endl;
        cout << "Snelheid: " << Voertuigen[i].getSnelheid() << endl;
        cout << "Versnelling: " <<  Voertuigen[i].getVersnelling()<<endl;
    }
}

void Baan::BerekenVersnellingGroen() {
    double volgafstand;
    double snelheidsverchil;
    double delta;
    double max = 0;
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()) ; i++) {
        if (i == 0){
            Voertuigen[i].setVersnelling(1.44 * (1-pow(Voertuigen[i].getVersnelling()/16.6,4))- pow(0,2));
            continue;
        }
        else{
            volgafstand = Voertuigen[i-1].getPositie() - Voertuigen[i].getPositie() - Voertuigen[i-1].getLengte();
            snelheidsverchil = Voertuigen[i].getSnelheid() - Voertuigen[i-1].getSnelheid();
            if (0 < (Voertuigen[i].getSnelheid()+((Voertuigen[i].getSnelheid() * snelheidsverchil)/2*sqrt(1.44*4.61)))){
                max =Voertuigen[i].getSnelheid()+((Voertuigen[i].getSnelheid()*snelheidsverchil)/2*sqrt(1.44*4.61));
            }
            delta = (4 + max)/volgafstand;
            Voertuigen[i].setVersnelling(1.44 * (1-pow(Voertuigen[i].getVersnelling()/16.6,4) - pow(delta,2)));
        }
    }
}

void Baan::BerekenVersnellingRood(double LightPos){
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()) ; i++) {
        if(i==0 && Voertuigen[i].getPositie() < LightPos - 50){
            Voertuigen[i].setVersnelling(-(4.61 * Voertuigen[i].getSnelheid())/(0.4*16.6));

        }
        else if(Voertuigen[i].getSnelheid() < (LightPos - 15)/2){
            Voertuigen[i].setSnelheid(0);
        }
        else{
            Voertuigen[i].setVersnelling(-(4.61 * Voertuigen[i].getSnelheid())/16.6);
        }
        // idea: loop through lights and check if theyre on red (loop doesnt have to be in current loop)
        // if its red stop all vehicles before the light
        // if its not then let vehicles drive normally

    }
}



void Baan::BerekenSnelheid() {
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()) ; ++i) {
        if (Voertuigen[i].getPositie() > this->lengte){
            Voertuigen.erase(Voertuigen.begin());
        }
        else if (Voertuigen[i].getSnelheid() + (Voertuigen[i].getVersnelling()*0.0166) < 0){
            Voertuigen[i].setPositie(Voertuigen[i].getPositie()-(pow(Voertuigen[i].getSnelheid(),2)/(2*Voertuigen[i].getVersnelling())));
            Voertuigen[i].setSnelheid(0);
        }
        else{
            Voertuigen[i].setSnelheid(Voertuigen[i].getSnelheid() + (Voertuigen[i].getVersnelling()*0.0166));
            double even = (Voertuigen[i].getPositie() + (Voertuigen[i].getSnelheid()*0.0166) + (Voertuigen[i].getVersnelling() * (pow(0.0166,2)/2)));
            Voertuigen[i].setPositie(even);
        }
    }
}




