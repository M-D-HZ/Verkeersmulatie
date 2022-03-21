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
        while (!banen[i].getVoertuigen().empty()){
            banen[i].PrintVoertuigen();
            banen[i].BerekenVersnelling();
            banen[i].BerekenSnelheid();
            verkeer.UpdateBanen(banen);
        }

    }
}
