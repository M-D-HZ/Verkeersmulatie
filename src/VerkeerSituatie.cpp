// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#include "VerkeerSituatie.h"
#include "Baan.h"
#include "Bushalte.h"
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
        string elemName = elem->Value();
        if (elemName == "BAAN") {
            Baan* baan = new Baan();
            for (TiXmlElement* lompo = elem->FirstChildElement(); lompo != NULL; lompo = lompo->NextSiblingElement()) {
                string elemNameto = lompo->Value();
                if (elemNameto == "naam") {
                    string even  = lompo->GetText();
                    baan->setNaam(lompo->GetText());
                }
                else if (elemNameto == "lengte") {
                    baan->setLengte(getal(lompo->GetText()));
                    this->Banen.push_back(baan);
                    ENSURE(!this->Banen.empty(),"There have added new road");
                }
            }
        }
        else if (elemName == "VERKEERSLICHT") {
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
            Voertuig* TruckSan = new Voertuig();
            for (TiXmlElement *elemto = elem->FirstChildElement(); elemto != NULL; elemto = elemto->NextSiblingElement()) {
                string elemNameto = elemto->Value();
                if (elemNameto == "baan") {
                    TruckSan->setBaan(elemto->GetText());
                }
                if (elemNameto == "positie") {
                    TruckSan->setPositie(getal(elemto->GetText()));
                }
                if (elemNameto == "type"){
                    TruckSan->setType(elemto->GetText());
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
        else if(elemName == "BUSHALTE"){
            Bushalte* halte = new Bushalte();
            for (TiXmlElement *elemto = elem->FirstChildElement(); elemto != NULL; elemto = elemto->NextSiblingElement()) {
                string elemNameto = elemto->Value();
                if (elemNameto == "baan") {
                    halte->setBaan(elemto->GetText());
                }
                if (elemNameto == "positie") {
                    halte->setPositie(getal(elemto->GetText()));
                }
                if (elemNameto == "wachttijd"){
                    halte->setWachttijd(getal(elemto->GetText()));
                    for (unsigned int i = 0; i < unsigned(this->Banen.size()); ++i) {
                        if (this->Banen[i]->getNaam() == halte->getBaan()) {
                            this->Banen[i]->setBushalte(halte);
                        }
                    }
                }
            }
        }
        else if (elemName == "KRUISPUNT"){
            Kruispunt* kruising = new Kruispunt();
            int index = 1;
            for (TiXmlElement *elemto = elem->FirstChildElement(); elemto != NULL; elemto = elemto->NextSiblingElement()) {
                string elemNameto = elemto->Value();
                string r = elemto->GetText();
                for (unsigned int i = 0; i < unsigned(this->Banen.size()); i++){
                    if (index == 1 && elemto->GetText() == Banen[i]->getNaam()){
                        kruising->setPunt1(make_pair(Banen[i],getal(elemto->Attribute("positie"))));
                        index++;
                    }
                    else if (index == 2 && elemto->GetText() == Banen[i]->getNaam()){
                        kruising->setPunt2(make_pair(Banen[i], getal(elemto->Attribute("positie"))));
                    }
                }
            }
            for (unsigned int i = 0; i < unsigned(this->Banen.size()) ; ++i) {
                if (Banen[i] == kruising->getPunt1().first or Banen[i] == kruising->getPunt2().first){
                    Banen[i]->setKruispunt(kruising);
                }
            }
        }
        else if(elemName == "VOERTUIGGENERATOR"){

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
bool VerkeerSituatie::isleeg(){
    for (unsigned int i = 0; i < Banen.size(); ++i) {
        if(!Banen[i]->getVoertuigen().empty())
            return false;
    }
    return true;
}

void VerkeerSituatie::start(){
    REQUIRE(this->properlyInitialized(),"It is not initialised");
    simulatie = 0;
    //this->read("Banen.xml"); // spec 1.0
    this->read("Banen1.xml"); // spec 2.0
    Tijdstip = -1; // Zet hier hoeveel tijdstippen je wilt simuleren
    bool leeg = false;
    while (!leeg){
        for (unsigned int i = 0; i < Banen.size(); ++i) {
            cout << "---> Tijd: "<< simulatie << endl;
            if(!Banen[i]->getVoertuigen().empty()){
                Banen[i]->ReduceCycle();
                Banen[i]->PrintVoertuigen();
                Banen[i]->Snelheid();
                Banen[i]->Versnelling();
            }
//            if(simulatie%500==0 && simulatie < 1000){
//                Banen[i]->setVoertuig(generator.NewVoertuig(Banen[i]->getNaam()));
//                cout<<"TOEGEVOEGD"<<endl<<endl<<endl;
//            }
        }
        leeg = isleeg();
        simulatie +=1;
    }
    ENSURE(leeg = false,"There shouldn't be any car left");
}






