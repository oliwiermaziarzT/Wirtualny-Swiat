#include "Trawa.h"

Trawa::Trawa(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek) : Roslina(swiat, x, y, sila, inicjatywa, wiek) {}

Organizm* Trawa::nowy(int nx, int ny){
    return new Trawa(swiat, nx, ny, 0, 0, 0);
}

void Trawa::rysowanie(){
    std::cout << "T";
}

std::string Trawa::getGatunek(){
    return "Trawa";
}
