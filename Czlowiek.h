#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
    private:
    int licznik = 0;
    int kierunek;
    public:
    Czlowiek(Swiat* swiat, int x, int y);
    virtual void akcja();
    virtual void kolizja(Organizm* inny);
    void rysowanie();
    void setKierunek(int kierunek);
    virtual std::string getGatunek();
    Organizm* nowy(int x, int y);
    virtual int getLicznik();
    virtual void setLicznik(int licznik);
};