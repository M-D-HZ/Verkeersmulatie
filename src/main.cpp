// Groep: Student 1: Anass Hamzaoui - s0210294
//        Student 2: X Tenzin Choezin - s0202163
#include <iostream>
#include "../tinyxml/tinyxml.h"
#include "ReadFile.h"
#include "VerkeerSituatie.h"

using namespace std;

int main() {
    VerkeerSituatie verkeer;
    verkeer.read("Banen.xml", verkeer);
    vector<Baan> banen = verkeer.GetBanen();
    for (unsigned int i = 0; i < banen.size(); ++i) {
        // reduce cyclus, getcyclus, switchlights
        vector<VerkeersLicht> lights = banen[i].getVerkeerslichten();
        while (!banen[i].getVoertuigen().empty()){
            for (unsigned int j = 0; j < lights.size(); j++) {
                lights[j].reduce();
                if(lights[j].getColor() == "red"){
                    cout << "light has turned red" << endl;
                    banen[i].BerekenVersnellingRood(lights[j].getPositie());
                    banen[i].BerekenSnelheid();
                    verkeer.UpdateBanen(banen);
                }
                else{
                    banen[i].BerekenVersnellingGroen();
                    banen[i].BerekenSnelheid();
                    verkeer.UpdateBanen(banen);
                }
            }

            banen[i].PrintVoertuigen();
//            banen[i].BerekenVersnellingGroen();
//            banen[i].BerekenSnelheid();
            verkeer.UpdateBanen(banen);
        }

    }
}
