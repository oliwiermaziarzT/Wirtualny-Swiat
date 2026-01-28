#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
    public:
    Zwierze(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek);
    void kolizja(Organizm* inny) override;
    void akcja() override;
};