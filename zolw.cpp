#include "Zolw.h"


Zolw::Zolw(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek) : Zwierze(swiat, x, y, sila, inicjatywa, wiek) {}


std::string Zolw::getGatunek(){
    return "Zolw";
}

void Zolw::rysowanie(){
    std::cout << "Z";
}

Organizm* Zolw::nowy(int nx, int ny) { 
    return new Zolw(swiat, nx, ny, 2, 1, 0); 
}

void Zolw::akcja(){
    if (rand() % 100 < 25) { 
        Zwierze::akcja();
    }   
}
void Zolw::kolizja(Organizm* inny) {
    if (this->getGatunek() == inny->getGatunek()) {
        Zwierze::kolizja(inny);
        return;
    }
    if (inny->getSila() < 5) {
        swiat->dodajKomunikat("Zolw odpiera atak " + inny->getGatunek() + " (" + std::to_string(x) + "," + std::to_string(y) + ")");
        return;
    }
    Zwierze::kolizja(inny); 
}