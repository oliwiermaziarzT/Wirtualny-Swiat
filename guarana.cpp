#include "Guarana.h"


Guarana::Guarana(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek) : Roslina(swiat, x, y, sila, inicjatywa, wiek){}

Organizm* Guarana::nowy(int nx, int ny){
    return new Guarana(swiat, nx, ny, 0, 0, 0);
}

void Guarana::rysowanie(){
    std::cout << "G";
}

std::string Guarana::getGatunek(){
    return "Guarana";
}

void Guarana::kolizja(Organizm* inny) {
    if (this->getSila() > inny->getSila()) {
        swiat->dodajKomunikat(this->getGatunek() + " otruwa " + inny->getGatunek() + " na (" + std::to_string(this->getX()) + "," + std::to_string(this->getY()) + ")");
        inny->kill();
    } else {
        swiat->dodajKomunikat(this->getGatunek() + " zostala zjedzona przez " + inny->getGatunek() + " na (" + std::to_string(this->getX()) + "," + std::to_string(this->getY()) + ")" + "(wzmocniono sile o 3)");
        inny->wzmocnienie(3);
        this->kill();
    }
}