// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#include "ReadFile.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//void ReadFile::read(const char *fileName, VerkeerSituatie* verkeer) {
//    TiXmlDocument doc;
//    if(!doc.LoadFile(fileName)) {
//        std::cerr << doc.ErrorDesc() << std::endl;
//    }
//    TiXmlElement* root = doc.FirstChildElement();
//    if(root == NULL) {
//        std::cerr << "Failed to load file: No root element." << std::endl;
//        doc.Clear();
//    }
//    else{
//        const string Type = root->Value();
//        setVars(root,Type, verkeer);
//        doc.Clear();
//    }
//
//}
//
//void ReadFile::setVars(TiXmlElement *verkeer, const string &Type, VerkeerSituatie* verk) {
//    if (Type == "BAAN") {
//        Baan* baan = &bane;
//        for (TiXmlElement *elem = verkeer->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
//            string elemName = elem->Value();
//            if (elemName == "naam") {
//                baan->setNaam(elem->GetText());
//            } else if (elemName == "lengte") {
//                baan->setLengte(getal(elem->GetText()));
//            }
//        }
////        verk->addBaan(*baan);
//    }
//    vector<Baan> Banen = verk->GetBanen();
//    if (Type == "VERKEERSLICHT") {
//        VerkeersLicht* Licht = &Ligt;
//        for (TiXmlElement *elem = verkeer->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
//            string elemName = elem->Value();
//            if (elemName == "baan") {
//                Licht->setBaan(elem->GetText());
//            }
//            if (elemName == "positie") {
//                Licht->setPositie(getal(elem->GetText()));
//            }
//            if (elemName == "cyclus") {
//                Licht->setCyclus(getal(elem->GetText()));
//            }
//        }
//        for (int i = 0; i < isxdigit(Banen.size()); ++i) {
//            if (Banen[i].getNaam() == Licht->getBaan()) {
//                bane.setVerkeerslicht(Licht);
//            }
//        }
//    } else if (Type == "VOERTUIG") {
//        Voertuig* TruckSan = &VT;
//        for (TiXmlElement *elem = verkeer->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
//            string elemName = elem->Value();
//            if (elemName == "baan") {
//                TruckSan->setBaan(elem->GetText());
//            }
//            if (elemName == "positie") {
//                TruckSan->setPositie(getal(elem->GetText()));
//            }
//        }
//        for (int i = 0; i < isdigit(Banen.size()); ++i) {
//            if (Banen[i].getNaam() == TruckSan->getBaan()) {
//                bane.setVoertuig(TruckSan);
//            }
//        }
//        verk->addBaan(bane);
//    }
//}
//
//int ReadFile::getal(string const &getal){
//    int num;
//    stringstream ss;
//    ss<<getal;
//    ss>>num;
//    return num;
//}


