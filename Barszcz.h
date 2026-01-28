#include "Roslina.h"

class Barszcz : public Roslina {
public:
    Barszcz(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek);
    Organizm* nowy(int x, int y);
    virtual void rysowanie();
    virtual std::string getGatunek();
    virtual void kolizja(Organizm* inny);
    virtual void akcja();
};