// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#include "VerkeerSituatie.h"
#include "Baan.h"
#include "VerkeersLicht.h"
#include "Voertuig.h"
#include <string>
#include <sstream>


VerkeerSituatie::VerkeerSituatie() {}

void VerkeerSituatie::addBaan(Baan weg) {
    Banen.push_back(weg);
}

vector<Baan> VerkeerSituatie::GetBanen() {
    return Banen;
}


void VerkeerSituatie::read(const char *fileName, VerkeerSituatie& verk) {
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
                    verk.Banen.push_back(*baan);
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
                    for (unsigned int i = 0; i < unsigned(verk.Banen.size()); ++i) {
                        if (verk.Banen[i].getNaam() == TruckSan->getBaan()) {
                            verk.Banen[i].setVoertuig(TruckSan);
                        }
                    }
                }
            }
        }
    }
}

int VerkeerSituatie::getal(string const &getal){
    int num;
    stringstream ss;
    ss<<getal;
    ss>>num;
    return num;
}

int VerkeerSituatie::getSimulatieTijd() const {
    return Tijdstip;
}

void VerkeerSituatie::setSimulatieTijd(int simulatieTijd) {
    Tijdstip = simulatieTijd;
}

void VerkeerSituatie::UpdateBanen(vector<Baan> ways) {
    Banen = ways;
}







