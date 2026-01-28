#include "Roslina.h"

class Trawa : public Roslina {
public:
    Trawa(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek);
    Organizm* nowy(int x, int y);
    virtual void rysowanie();
    virtual std::string getGatunek();
};