// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#include <fstream>
#include <sstream>
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

vector<Voertuig*> Baan::getVoertuigen(){
    REQUIRE(this->properlyInit(), "Not properly initialized");
//ENSURE(!Voertuigen.empty(), "er zijn geen voertuigen");
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
string intTostring(int integer){
    stringstream ss;
    string str;
    ss << integer;
    ss >> str;
    return str;
}

void Baan::PrintVoertuigen(int Tijd) {
    REQUIRE(this->properlyInit(), "Not properly initialized");
    REQUIRE(!this->Voertuigen.empty(), "Nothing to print");
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()) ; ++i) {
        cout << "Tijd: " << Tijd << endl;
        cout << "---> Baan: " << Voertuigen[i]->getBaan() << endl;
        cout << "---> Positie: " << Voertuigen[i]->getPositie() << endl;
        cout << "---> Snelheid: " << Voertuigen[i]->getSnelheid() << endl;
        cout << "---> Versnelling: " <<  Voertuigen[i]->getVersnelling() << endl;
    }
}

void Baan::Sorteren(){
    for (unsigned int i = 0; i < unsigned(Voertuigen.size()) ; i++) {
        if (Voertuigen[i+1] == NULL){
            break;
        }
        else if (Voertuigen[i]->getPositie() < Voertuigen[i+1]->getPositie()){
            Voertuig* switchs = Voertuigen[i];
            Voertuigen[i] = Voertuigen[i+1];
            Voertuigen[i+1] = switchs;
            Sorteren();
        }
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

void Baan::setBushalte(Bushalte* halte) {
    Bushaltes.push_back(halte);
}

void Baan::setKruispunt(Kruispunt* kruising) {
    Kruispunten.push_back(kruising);
}

void Baan::MakeOutput(int Tijd) {
    fstream outfile;
    outfile.open("Verkeer.txt",ios::ate|ios::app);

    outfile << "Tijd: " << Tijd << endl;
    outfile << naam << '\t' << " | ";
    for (unsigned int i = 0; i < unsigned(lengte); i++) {
        for (unsigned int j = 0; j < unsigned(Voertuigen.size()); j++) {
            if (Voertuigen[j]->getPositie() > i && Voertuigen[j]->getPositie() < i+Voertuigen[j]->getLengte() && Voertuigen[j]->getType() == "auto"){
                for (unsigned int k = 0; k < unsigned(Voertuigen[j]->getLengte()); k++) {
                    outfile << "A";
                    i++;
                }
            }
            else if (Voertuigen[j]->getPositie() > i && Voertuigen[j]->getPositie() < i+Voertuigen[j]->getLengte() && Voertuigen[j]->getType() == "bus"){
                for (unsigned int k = 0; k < unsigned(Voertuigen[j]->getLengte()); k++) {
                    outfile << "B";
                    i++;
                }
            }
            else if (Voertuigen[j]->getPositie() > i && Voertuigen[j]->getPositie() < i+Voertuigen[j]->getLengte() && Voertuigen[j]->getType() == "brandweerwagen"){
                for (unsigned int k = 0; k < unsigned(Voertuigen[j]->getLengte()); k++) {
                    outfile << "W";
                    i++;
                }
            }
            else if (Voertuigen[j]->getPositie() > i && Voertuigen[j]->getPositie() < i+Voertuigen[j]->getLengte() && Voertuigen[j]->getType() == "ziekenwagen"){
                for (unsigned int k = 0; k < unsigned(Voertuigen[j]->getLengte()); k++) {
                    outfile << "Z";
                    i++;
                }
            }
            else if (Voertuigen[j]->getPositie() > i && Voertuigen[j]->getPositie() < i+Voertuigen[j]->getLengte() && Voertuigen[j]->getType() == "politiecombi"){
                for (unsigned int k = 0; k < unsigned(Voertuigen[j]->getLengte()); k++) {
                    outfile << "P";
                    i++;
                }
            }
            else{
                outfile << "=";
            }
        }
    }
    outfile << endl;
//    outfile << " > verkeerslichten" << '\t' << " | ";
//    for (unsigned int i = 0; i < unsigned(lengte); i++) {
//        for (unsigned int j = 0; j < unsigned(Verkeerslichten.size()); j++) {
//            if (i+15 == Verkeerslichten[j]->getPositie()){
//                outfile << "|";
//                i++;
//            }
//            else if (Verkeerslichten[j]->getPositie() == i && Verkeerslichten[j]->getColor() == "red"){
//                outfile << "R";
//                i++;
//            }
//            else if (Verkeerslichten[j]->getPositie() == i && Verkeerslichten[j]->getColor() == "green"){
//                outfile << "G";
//                i++;
//            }
//            else{
//                outfile << " ";
//            }
//        }
//    }
//    outfile << endl;
//    outfile << " > bushaltes" << '\t' << " | ";
//    for (int j = 0; j < unsigned(lengte); j++) {
//        for (unsigned int i = 0; i < unsigned(Bushaltes.size()); i++) {
//            if (Bushaltes[i]->getPositie() == j) {
//                outfile << "B";
//                j++;
//            }
//            else{
//                outfile << " ";
//            }
//        }
//    }
//    outfile << endl;
    outfile.close();
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



