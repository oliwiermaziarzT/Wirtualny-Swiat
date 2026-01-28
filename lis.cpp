#include "Lis.h"


Lis::Lis(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek) : Zwierze(swiat, x, y, sila, inicjatywa, wiek) {}


std::string Lis::getGatunek(){
    return "Lis";
}

void Lis::rysowanie(){
    std::cout << "L";
}

Organizm* Lis::nowy(int nx, int ny) { 
    return new Lis(swiat, nx, ny, 4, 4, 0); 
}

void Lis::akcja(){
    int nowyX = x;
    int nowyY = y;

    int kierunek = rand() % 4;
    if(kierunek == 0 && y > 0) nowyY--;
    else if(kierunek == 1 && y < 19) nowyY++;
    else if(kierunek == 2 && x > 0) nowyX--;
    else if(kierunek == 3 && x < 19) nowyX++;

    if(nowyX == x && nowyY == y){
        return;
    }

    if(nowyX >= 0 && nowyX < 20 && nowyY >= 0 && nowyY < 20){
        Organizm* pole = swiat->getZPola(nowyX, nowyY);
        if(pole == nullptr){
            swiat->ustawNaPolu(x, y, nullptr);
            x = nowyX;
            y = nowyY;
            swiat->ustawNaPolu(x, y, this);
        }
        else {
            if(pole->getGatunek() == this->getGatunek()){
                pole->kolizja(this);
            }
            else if(pole->getSila() <= this->getSila()){
                pole->kolizja(this);
                if(this->isAlive() && !pole->isAlive()){
                    swiat->ustawNaPolu(x, y, nullptr);
                    x = nowyX;
                    y = nowyY;
                    swiat->ustawNaPolu(x, y, this);
                }
            }
        }
    }   

}