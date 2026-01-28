#include "Jagody.h"

Jagody::Jagody(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek) : Roslina(swiat, x, y, sila, inicjatywa, wiek) {}

Organizm* Jagody::nowy(int nx, int ny){
    return new Jagody(swiat, nx, ny, 99, 0, 0);
}

void Jagody::rysowanie(){
    std::cout << "J";
}

std::string Jagody::getGatunek(){
    return "Jagoda";
}

void Jagody::kolizja(Organizm* inny){
        swiat->dodajKomunikat(inny->getGatunek() + " zjada " + "jagody i ginie" + " na (" + std::to_string(this->getX()) + "," + std::to_string(this->getY()) + ")");
        inny->kill();
        this->kill();
}
