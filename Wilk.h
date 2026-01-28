#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
    public:
    Wilk(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek);
    virtual void rysowanie();
    virtual std::string getGatunek();
    Organizm* nowy(int x, int y);
};