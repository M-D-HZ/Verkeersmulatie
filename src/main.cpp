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
    for (unsigned int i = 0; i < verkeer.GetBanen().size(); ++i) {
        while (!verkeer.GetBanen()[i].getVoertuigen().empty()){
            verkeer.GetBanen()[i].PrintVoertuigen();
        }
    }
}
