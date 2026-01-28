#include "Roslina.h"

class Mlecz : public Roslina {
public:
    Mlecz(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek);
    Organizm* nowy(int x, int y);
    virtual void rysowanie();
    virtual std::string getGatunek();
    virtual void akcja() override;
};