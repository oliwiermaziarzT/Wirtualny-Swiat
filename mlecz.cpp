#include "Mlecz.h"

Mlecz::Mlecz(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek) : Roslina(swiat, x, y, sila, inicjatywa, wiek) {}

Organizm* Mlecz::nowy(int nx, int ny){
    return new Mlecz(swiat, nx, ny, 0, 0, 0);
}

void Mlecz::rysowanie(){
    std::cout << "M";
}

std::string Mlecz::getGatunek(){
    return "Mlecz";
}

void Mlecz::akcja() {
    for (int i = 0; i < 3; i++) {
        if (rand() % 100 < 3) { 
        int proby = 0;
        
        while (proby < 10) {
            int dx = (rand() % 3) - 1;
            int dy = (rand() % 3) - 1;

            if (dx == 0 && dy == 0) {
                proby++;
                continue;
            }

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < 20 && ny >= 0 && ny < 20) {
                Organizm* pole = swiat->getZPola(nx, ny);
                

                if (pole == nullptr) {
                    swiat->dodajOrganizm(this->nowy(nx, ny));
                    swiat->dodajKomunikat(this->getGatunek() + " rozsiewa sie na (" + std::to_string(nx) + "," + std::to_string(ny) + ")");
                    break;
                }
            }
            proby++; 
        }
    }
    }
}
