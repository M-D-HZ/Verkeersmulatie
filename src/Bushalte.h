#ifndef UNTITLED_BUSHALTE_H
#define UNTITLED_BUSHALTE_H
#include "iostream"
#include "map"
#include "vector"

using namespace std;

class Bushalte {
    string baan;
    int positie;
    int wachttijd;
public:
    Bushalte();

    const string &getBaan() const;

    void setBaan(const string &baan);

    int getPositie() const;

    void setPositie(int positie);

    int getWachttijd() const;

    void setWachttijd(int wachttijd);
};


#endif //UNTITLED_BUSHALTE_H
