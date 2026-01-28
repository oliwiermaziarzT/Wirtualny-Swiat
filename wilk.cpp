#include "Wilk.h"

Wilk::Wilk(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek) : Zwierze(swiat, x, y, sila, inicjatywa, wiek) {}

std::string Wilk::getGatunek(){
    return "Wilk";
}

void Wilk::rysowanie(){
    std::cout << "W";
}
Organizm* Wilk::nowy(int nx, int ny) { 
    return new Wilk(swiat, nx, ny, 9, 5, 0); 
}
