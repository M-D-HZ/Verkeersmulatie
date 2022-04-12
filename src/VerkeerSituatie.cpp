// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#include "VerkeerSituatie.h"
#include "Baan.h"
#include "VerkeersLicht.h"
#include "Voertuig.h"
#include <string>
#include <sstream>
#include "DesignByContract.h"



VerkeerSituatie::VerkeerSituatie() {
    isThis = this;
    this->start(); // 8:30
}
bool VerkeerSituatie::properlyInitialized() {
    if(isThis == this){
        return true;
    }
    return false;
}

void VerkeerSituatie::addBaan(Baan weg){
    REQUIRE(properlyInitialized(),"het is geinitialiseerd");
    unsigned int i= Banen.size();
    Banen.push_back(&weg);
    ENSURE(unsigned(Banen.size()) == unsigned(i+1), "New road has been added");

}

vector<Baan*> VerkeerSituatie::GetBanen() {
    REQUIRE(properlyInitialized(),"It is initialised");
    ENSURE(!Banen.empty(),"Banen is empty");
    return Banen;
}


void VerkeerSituatie::read(const char *fileName) {
    REQUIRE((*fileName != ' ') && (this->properlyInitialized()), "input file has a name and/or it is initialised");
    TiXmlDocument doc;
    if(!doc.LoadFile(fileName)) {
        std::cerr << doc.ErrorDesc() << std::endl;
    }
    TiXmlElement* root = doc.FirstChildElement();
    if(root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
    }

    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        TiXmlElement* lopo = root->FirstChildElement();
        string elemName = elem->Value();
        if (elemName == "BAAN") {
            Baan* baan = new Baan();
            for (TiXmlElement* elemto = lopo->FirstChildElement(); elemto != NULL; elemto = elemto->NextSiblingElement()) {
                string elemNameto = elemto->Value();
                if (elemNameto == "naam") {
                    baan->setNaam(elemto->GetText());
                }
                else if (elemNameto == "lengte") {
                    baan->setLengte(getal(elemto->GetText()));
                    this->Banen.push_back(baan);
                    ENSURE(!this->Banen.empty(),"There have added new road");
                }
            }
        }
        if (elemName == "VERKEERSLICHT") {
            VerkeersLicht* Licht = new VerkeersLicht();
            for (TiXmlElement *elemto = elem->FirstChildElement(); elemto != NULL; elemto = elemto->NextSiblingElement()) {
                string elemNameto = elemto->Value();
                if (elemNameto == "baan") {
                    Licht->setBaan(elemto->GetText());
                }
                if (elemNameto == "positie") {
                    Licht->setPositie(getal(elemto->GetText()));
                }
                if (elemNameto == "cyclus") {
                    Licht->setCyclus(getal(elemto->GetText()));
                    Licht->setClone(getal(elemto->GetText()));
                    for (unsigned int i = 0; i < unsigned(this->Banen.size()); i++) {
//                        string k = verk.Banen[i].getNaam();
                        if (this->Banen[i]->getNaam() == Licht->getBaan()) {
                            int ev = this->Banen[i]->getLichtSize();
                            this->Banen[i]->setVerkeerslicht(Licht);
                            ENSURE(unsigned(this->Banen[i]->getLichtSize()) == unsigned(ev+1),"you have added new trafic lights");
//                        delete Licht;
                        }
                    }
                }
            }
        }
        else if (elemName == "VOERTUIG") {
            Voertuig* TruckSan = new Voertuig(4);
            for (TiXmlElement *elemto = elem->FirstChildElement(); elemto != NULL; elemto = elemto->NextSiblingElement()) {
                string elemNameto = elemto->Value();
                if (elemNameto == "baan") {
                    TruckSan->setBaan(elemto->GetText());
                }
                if (elemNameto == "positie") {
                    TruckSan->setPositie(getal(elemto->GetText()));
                    TruckSan->setLengte(4);
                    for (unsigned int i = 0; i < unsigned(this->Banen.size()); ++i) {
                        if (this->Banen[i]->getNaam() == TruckSan->getBaan()) {
                            int ev = this->Banen[i]->getVoertuigSize();
                            this->Banen[i]->setVoertuig(TruckSan);
                            ENSURE((unsigned(this->Banen[i]->getVoertuigSize()) == unsigned (ev +1)),"You have added new car");
                        }
                    }
                }
            }
        }
    }
}

int VerkeerSituatie::getal(string const &getal){
    REQUIRE((getal != "") ,"Je mag geen lege string hebben");
    unsigned int num;
    stringstream ss;
    ss<<getal;
    ss>>num;
    ENSURE(num > 0,"There are no negative positions");
    return num;
}

int VerkeerSituatie::getSimulatieTijd(){
    REQUIRE(this->properlyInitialized(),"It is initialised");
    ENSURE(Tijdstip>0,"Verschill in tijd is nooit negatief");
    return Tijdstip;
}

void VerkeerSituatie::setSimulatieTijd(int simulatieTijd) {
    REQUIRE(this->properlyInitialized(),"It is initialised");
    ENSURE(Tijdstip>0,"Tijd is nooit negatief");
    Tijdstip = simulatieTijd;
}

void VerkeerSituatie::UpdateBanen(vector<Baan*> ways) {
    REQUIRE(this->properlyInitialized(),"It is not initialised");
    Banen = ways;
//    ENSURE(this->GetBanen() == ways,"Baan has to change to the new vector of Baan");
}

void VerkeerSituatie::start(){
    REQUIRE(this->properlyInitialized(),"It is not initialised");
    simulatie = 0;
    this->read("Banen.xml"); // 8:30
    Tijdstip = -1; // Zet hier hoeveel tijdstippen je wilt simuleren
    for (unsigned int i = 0; i < Banen.size(); ++i) {
        while (!Banen[i]->getVoertuigen().empty() && simulatie != Tijdstip){
            cout << "---> Tijd: "<< simulatie << endl;
            if (simulatie == 2062){
                cout << "oopsiewoopsiemadeappopsie" << endl;
            }
            Banen[i]->ReduceCycle();
            Banen[i]->PrintVoertuigen();
            Banen[i]->Snelheid();
            Banen[i]->Versnelling();
            simulatie +=1;
        }
        ENSURE(Banen[i]->getVoertuigen().empty(),"There shouldn't be any car left");
    }
}






