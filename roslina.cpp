#include "Roslina.h"
#include <format>
Roslina::Roslina(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek) : Organizm(swiat, x, y, sila, inicjatywa, wiek) {}

void Roslina::akcja() {
    if (rand() % 100 < 5) { 
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


void Roslina::kolizja(Organizm* inny) {
    if (this->getSila() > inny->getSila()) {
        swiat->dodajKomunikat(this->getGatunek() + " otruwa " + inny->getGatunek() + " na (" + std::to_string(this->getX()) + "," + std::to_string(this->getY()) + ")");
        inny->kill();
    } else {
        swiat->dodajKomunikat(this->getGatunek() + " zostala zjedzona przez " + inny->getGatunek() + " na (" + std::to_string(this->getX()) + "," + std::to_string(this->getY()) + ")");
        this->kill();
    }
}