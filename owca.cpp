#include "Owca.h"


Owca::Owca(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek) : Zwierze(swiat, x, y, sila, inicjatywa, wiek) {}


std::string Owca::getGatunek(){
    return "Owca";
}

void Owca::rysowanie(){
    std::cout << "O";
}

Organizm* Owca::nowy(int nx, int ny) { 
    return new Owca(swiat, nx, ny, 4, 4, 0); 
}
