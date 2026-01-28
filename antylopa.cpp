#include "Antylopa.h"

Antylopa::Antylopa(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek) : Zwierze(swiat, x, y, sila, inicjatywa, wiek) {}

std::string Antylopa::getGatunek(){
    return "Antylopa";
}

void Antylopa::rysowanie(){
    std::cout << "A";
}
Organizm* Antylopa::nowy(int nx, int ny) { 
    return new Antylopa(swiat, nx, ny, 4, 4, 0); 
}

void Antylopa::akcja(){
    int nowyX = x;
    int nowyY = y;
    int kierunek = rand() % 4;
    
    if(kierunek == 0 && y >= 2) nowyY -= 2;
    else if(kierunek == 1 && y < 18) nowyY += 2;
    else if(kierunek == 2 && x >= 2) nowyX -= 2;
    else if(kierunek == 3 && x < 18) nowyX += 2;

    if(nowyX == x && nowyY == y) return;

    if(nowyX >= 0 && nowyX < 20 && nowyY >= 0 && nowyY < 20){
        Organizm* pole = swiat->getZPola(nowyX, nowyY);
        if(pole == nullptr){
            swiat->ustawNaPolu(x, y, nullptr);
            x = nowyX;
            y = nowyY;
            swiat->ustawNaPolu(x, y, this);
        }
        else if(pole != this){
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
void Antylopa::kolizja(Organizm* inny) {
    if(this==inny){
        return;
    }
    if (this->getGatunek() == inny->getGatunek()){
        Zwierze::kolizja(inny);
        return;
    }
    
    if (rand() % 100 < 50) {
        int proby = 0;
        while (proby < 10) {
            int dx = (rand() % 3) - 1;
            int dy = (rand() % 3) - 1;
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < 20 && ny >= 0 && ny < 20 && swiat->getZPola(nx, ny) == nullptr) {
                swiat->dodajKomunikat("Antylopa ucieka przed walka na (" + std::to_string(nx) + "," + std::to_string(ny) + ")");
                swiat->ustawNaPolu(x, y, nullptr);
                x = nx;
                y = ny;
                swiat->ustawNaPolu(x, y, this);
                return;
            }
            proby++;
        }
    }

    if (inny->getSila() >= this->getSila()) {
        this->kill();
    } else {
        inny->kill();
    }

    
}
