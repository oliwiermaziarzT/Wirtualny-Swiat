#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
    public:
    Owca(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek);
    virtual void rysowanie();
    virtual std::string getGatunek();
    Organizm* nowy(int x, int y);
};