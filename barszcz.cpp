#include "Barszcz.h"
#include "Zwierze.h"

Barszcz::Barszcz(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek) : Roslina(swiat, x, y, sila, inicjatywa, wiek) {}

Organizm* Barszcz::nowy(int nx, int ny){
    return new Barszcz(swiat, nx, ny, 99, 0, 0);
}

void Barszcz::rysowanie(){
    std::cout << "B";
}

std::string Barszcz::getGatunek(){
    return "Barszcz";
}

void Barszcz::akcja() {
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;

            int nx = x + dx;
            int ny = y + dy;
            
            if (nx >= 0 && nx < 20 && ny >= 0 && ny < 20) {
                Organizm* sasiad = swiat->getZPola(nx, ny);
                if (sasiad != nullptr) {
                    Zwierze* zwierze = dynamic_cast<Zwierze*>(sasiad);
                    if (zwierze != nullptr && sasiad->getGatunek() != "Cyber-Owca") {
                        swiat->dodajKomunikat("Barszcz wypalil " + sasiad->getGatunek() + " na (" + std::to_string(nx) + "," + std::to_string(ny) + ")");
                        sasiad->kill();
                    }
                }
            }
        }
    }
    Roslina::akcja();
}

void Barszcz::kolizja(Organizm* inny){
    inny->kill();
    swiat->dodajKomunikat(this->getGatunek() + " zabil " + inny->getGatunek() + " na (" + std::to_string(getX()) + "," + std::to_string(getY()) + ")");
}