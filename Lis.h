#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
    public:
    Lis(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek);
    virtual void rysowanie();
    virtual std::string getGatunek();
    Organizm* nowy(int x, int y);
    virtual void akcja();
};