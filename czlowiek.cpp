#include "Czlowiek.h"
#include <cmath>
Czlowiek::Czlowiek(Swiat* swiat, int x, int y) 
    : Zwierze(swiat, x, y, 5, 4, 0) { 
    this->kierunek = -1; 
    this->licznik = 0;
}
std::string Czlowiek::getGatunek(){
    return "Czlowiek";
}

void Czlowiek::rysowanie(){
    std::cout << "C";
}

void Czlowiek::akcja(){
    if(licznik > 5){
        licznik--;
        if(licznik == 5){
            swiat->dodajKomunikat("Umiejetnosc Czlowieka skonczyla sie, rozpoczyna sie odnowienie.");
            swiat->dodajKomunikat("Umiejetnosc Czlowieka w trakcie odnowienia, pozostalo tur: " + std::to_string(licznik));
        } else{
        swiat->dodajKomunikat("Umiejetnosc Czlowieka aktywna, pozostalo tur: " + std::to_string(licznik - 5));
        } 
    } else if(licznik > 0 && licznik <= 5){
        licznik--;
        if(licznik == 0){
            swiat->dodajKomunikat("Umiejetnosc Czlowieka gotowa do uzycia.");
        }
        if(licznik != 0){
            swiat->dodajKomunikat("Umiejetnosc Czlowieka w trakcie odnowienia, pozostalo tur: " + std::to_string(licznik));
        }
    } 

    if(kierunek == 4){
        if(licznik == 0){
            licznik = 10;
            swiat->dodajKomunikat("Czlowiek uzywa umiejetnosci!");
        } 
        else {
            swiat->dodajKomunikat("Umiejetnosc jest juz aktywna lub w trakcie odnowienia!");
        }
    }
    int nowyX = x;
    int nowyY = y;

    if(kierunek == 0 && y > 0) nowyY--;
    else if(kierunek == 1 && y < 19) nowyY++;
    else if(kierunek == 2 && x > 0) nowyX--;
    else if(kierunek == 3 && x < 19) nowyX++;

    if(nowyX != x || nowyY != y){
        Organizm* pole = swiat->getZPola(nowyX, nowyY);
        if(pole == nullptr){
            swiat->ustawNaPolu(x, y, nullptr);
            x = nowyX;
            y = nowyY;
            swiat->ustawNaPolu(x, y, this);
        }
        else {
            if (licznik > 5) {
                this->kolizja(pole); 
                if (swiat->getZPola(nowyX, nowyY) == nullptr) {
                    swiat->ustawNaPolu(x, y, nullptr);
                    x = nowyX; y = nowyY;
                    swiat->ustawNaPolu(x, y, this);
                }
            } else {
                pole->kolizja(this);
                if (this->isAlive() && !pole->isAlive()) {
                    swiat->ustawNaPolu(x, y, nullptr);
                    x = nowyX; y = nowyY;
                    swiat->ustawNaPolu(x, y, this);
                }
            }
        }
    }
    kierunek = -1; 
}

void Czlowiek::kolizja(Organizm* inny){
    if(licznik > 5){
         for(int dx = -1; dx <= 1; dx++){
            for(int dy = -1; dy <= 1; dy++){
                if(dx == 0 && dy == 0) continue;

                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && nx < 20 && ny >= 0 && ny < 20){
                    if(swiat->getZPola(nx, ny) == nullptr){
                        int staryX = inny->getX();
                        int staryY = inny->getY();
                        swiat->ustawNaPolu(staryX, staryY, nullptr);
                        inny->setX(nx);
                        inny->setY(ny);
                        swiat->ustawNaPolu(nx, ny, inny);
                        swiat->dodajKomunikat("Czlowiek odpycha " + inny->getGatunek() + " dzieki Tarczy Azula!");
                        return;
                    }
                }
            }
         }
        return;
    }
    Zwierze::kolizja(inny);
}

Organizm* Czlowiek::nowy(int x, int y){
    return new Czlowiek(swiat, x, y);
}

void Czlowiek::setKierunek(int kierunek){
    this->kierunek = kierunek;
}

int Czlowiek::getLicznik(){
    return licznik;
}

void Czlowiek::setLicznik(int licznik){
    this->licznik = licznik;
}



