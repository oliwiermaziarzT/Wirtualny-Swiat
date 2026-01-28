#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
    public:
    Roslina(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek);
    void kolizja(Organizm* inny);
    void akcja();
};