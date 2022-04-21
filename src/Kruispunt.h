#ifndef UNTITLED_KRUISPUNT_H
#define UNTITLED_KRUISPUNT_H

#include "iostream"
#include "map"
#include "vector"
//#include "Baan.h"


using namespace std;
class Baan;
class Kruispunt {
    pair<Baan*,int > Punt1;
    pair<Baan*,int > Punt2;
public:
    Kruispunt();

    const pair<Baan *, int> &getPunt1() const;

    void setPunt1(const pair<Baan *, int> &punt1);

    const pair<Baan *, int> &getPunt2() const;

    void setPunt2(const pair<Baan *, int> &punt2);
};


#endif //UNTITLED_KRUISPUNT_H
