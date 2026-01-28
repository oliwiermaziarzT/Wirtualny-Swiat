#include "Zwierze.h"

Zwierze::Zwierze(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek) : Organizm(swiat, x, y, sila, inicjatywa, wiek){}


void Zwierze::akcja(){
    int nowyX = x;
    int nowyY = y;

    int kierunek = rand() % 4;
    if(kierunek == 0 && y > 0) nowyY--;
    else if(kierunek == 1 && y < 19) nowyY++;
    else if(kierunek == 2 && x > 0) nowyX--;
    else if(kierunek == 3 && x < 19) nowyX++;

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
void Zwierze::kolizja(Organizm* inny) {
    if(this==inny){
        return;
    }
    if(this->getWiek() > 5 && inny->getWiek() > 5){
        if (this->getGatunek() == inny->getGatunek()) {
            int proby = 0;
            bool znaleziono = false;

            while (proby < 10 && !znaleziono) {
                int dx = (rand() % 3) - 1; 
                int dy = (rand() % 3) - 1;

                if (dx == 0 && dy == 0) continue;
                
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < 20 && ny >= 0 && ny < 20) {
                    if (swiat->getZPola(nx, ny) == nullptr) {
                        swiat->dodajOrganizm(this->nowy(nx, ny));
                        swiat->dodajKomunikat(this->getGatunek() + " urodzil sie na (" + std::to_string(nx) + "," + std::to_string(ny) + ")");
                        znaleziono = true;
                    }
                }
                proby++;
            }
            return;
        } 
    
        else { 
            if(inny->getSila() >= this->getSila()){
                swiat->dodajKomunikat(inny->getGatunek() + " zabil " + this->getGatunek() + " na (" + std::to_string(inny->getX()) + "," + std::to_string(inny->getY()) + ")");
                this->kill();
            } else {
                swiat->dodajKomunikat(this->getGatunek() + " zabil " + inny->getGatunek() + " na (" + std::to_string(this->getX()) + "," + std::to_string(this->getY()) + ")");
                inny->kill();
            } 
        }
    }
}