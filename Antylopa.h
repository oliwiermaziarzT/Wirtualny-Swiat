#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze {
    public:
    Antylopa(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek);
    virtual void kolizja(Organizm* inny);
    virtual void akcja();
    virtual void rysowanie();
    virtual std::string getGatunek();
    Organizm* nowy(int x, int y);
};