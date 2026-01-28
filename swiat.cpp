#include "Swiat.h"
#include "Organizm.h"
#include "Wilk.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Jagody.h"
#include "Barszcz.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Czlowiek.h"
#include <iostream>
#include <algorithm>
#include <format>
using namespace std;

Swiat::Swiat() {
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            plansza[i][j] = nullptr;
        }
    }
}

void Swiat::setNastepnyRuch(int r){
    nastepnyRuch = r;
}

void Swiat::rysujSwiat(){
    for(int i = 0; i < M + 2; i++){
        cout << "#";
    }
    cout << endl;

    for(int i = 0; i < N; i++){
        cout << "#";
        for(int j = 0; j < M; j++){
            if(plansza[i][j] != nullptr && plansza[i][j]->isAlive()){
                plansza[i][j]->rysowanie();
            } 
            else {
                cout << ".";
            }
        }
        
        cout << "#" << endl;
    }
    for(int i = 0; i < M + 2; i++){
        cout << "#";
    }
    cout << endl;
    cout << "*************************************************" << endl;
    cout << "Komunikaty z tury:" << endl;
    for(auto& k : komunikaty) std::cout << k << endl;
    komunikaty.clear();
}
    
void Swiat::ustawNaPolu(int x, int y, Organizm* o) {
    plansza[y][x] = o;
}

Organizm* Swiat::getZPola(int x, int y){
    return plansza[y][x];
}

void Swiat::dodajOrganizm(Organizm* o){
    organizmy.push_back(o);
    ustawNaPolu(o->getX(), o->getY(), o);
}
bool porownanie(Organizm* a, Organizm* b){
    if(a->getInicjatywa() != b->getInicjatywa()){
        return a->getInicjatywa() > b->getInicjatywa();
    }
    return a->getWiek() > b->getWiek();    
}

void Swiat::wykonajTure(){
    std::sort(organizmy.begin(), organizmy.end(), porownanie);

    int ol = organizmy.size();
    for (int i = 0; i < ol; i++){
        if(organizmy[i]->isAlive()){
            if(organizmy[i]->getGatunek() == "Czlowiek"){
                static_cast<Czlowiek*>(organizmy[i])->setKierunek(nastepnyRuch);
            }
            organizmy[i]->akcja();
            organizmy[i]->zwiekszWiek();
        }
    }
    nastepnyRuch = -1;
    sprzataczka();
}

void Swiat::sprzataczka() {
    for (int i = organizmy.size() - 1; i >= 0; i--) {
        if (!organizmy[i]->isAlive()) {
            Organizm* doUsuniecia = organizmy[i];
            if(getZPola(doUsuniecia->getX(), doUsuniecia->getY()) == doUsuniecia){
                ustawNaPolu(doUsuniecia->getX(), doUsuniecia->getY(), nullptr);
            }
            organizmy.erase(organizmy.begin() + i);
            delete doUsuniecia;
        }
    }
}

void Swiat::dodajKomunikat(std::string s){
    komunikaty.push_back(s);
}

void Swiat::moby(){

    dodajOrganizm(new Czlowiek(this,  rand() % 20, rand() % 20));
    dodajOrganizm(new Wilk(this, rand() % 20, rand() % 20, 9, 5, 5));
    dodajOrganizm(new Wilk(this, rand() % 20, rand() % 20, 9, 5, 5));
    dodajOrganizm(new Wilk(this, rand() % 20, rand() % 20, 9, 5, 5));
    dodajOrganizm(new Owca(this, rand() % 20, rand() % 20, 4, 4, 5));
    dodajOrganizm(new Owca(this, rand() % 20, rand() % 20, 4, 4, 5));
    dodajOrganizm(new Owca(this, rand() % 20, rand() % 20, 4, 4, 5));
    dodajOrganizm(new Lis(this, rand() % 20, rand() % 20, 3, 7, 5));
    dodajOrganizm(new Lis(this, rand() % 20, rand() % 20, 3, 7, 5));
    dodajOrganizm(new Lis(this, rand() % 20, rand() % 20, 3, 7, 5));
    dodajOrganizm(new Zolw(this, rand() % 20, rand() % 20, 2, 1, 5));
    dodajOrganizm(new Zolw(this, rand() % 20, rand() % 20, 2, 1, 5));
    dodajOrganizm(new Zolw(this, rand() % 20, rand() % 20, 2, 1, 5));
    dodajOrganizm(new Antylopa(this, rand() % 20, rand() % 20, 4, 4, 5));
    dodajOrganizm(new Antylopa(this, rand() % 20, rand() % 20, 4, 4, 5));
    dodajOrganizm(new Antylopa(this, rand() % 20, rand() % 20, 4, 4, 5));
    dodajOrganizm(new Trawa(this, rand() % 20, rand() % 20, 0, 0, 0));
    dodajOrganizm(new Mlecz(this, rand() % 20, rand() % 20, 0, 0, 0));
    dodajOrganizm(new Guarana(this, rand() % 20, rand() % 20, 0, 0, 0));
    dodajOrganizm(new Jagody(this, rand() % 20, rand() % 20, 99, 0, 0));
    dodajOrganizm(new Barszcz(this, rand() % 20, rand() % 20, 10, 0, 0));
}

void Swiat::zapiszSwiat() {
    std::ofstream plik("stan_gry.txt");
    if (plik.is_open()) {
        plik << N << " " << M << " " << organizmy.size() << "\n";
        
        for (auto& o : organizmy) {
            plik << o->getGatunek() << " " 
                 << o->getX() << " " 
                 << o->getY() << " " 
                 << o->getSila() << " " 
                 << o->getWiek();
            
            if (o->getGatunek() == "Czlowiek") {
                plik << " " << static_cast<Czlowiek*>(o)->getLicznik();
            }
            plik << "\n";
        }
        plik.close();
        dodajKomunikat("Stan gry zostal zapisany do pliku stan_gry.txt");
    }
}

void Swiat::wczytajSwiat() {
    std::ifstream plik("stan_gry.txt");
    if (plik.is_open()) {
        for (auto& o : organizmy) delete o;
        organizmy.clear();
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < M; j++) plansza[i][j] = nullptr;

        int size;
        int tempN, tempM;
        plik >> tempN >> tempM >> size;

        for (int i = 0; i < size; i++) {
            std::string gatunek;
            int x, y, sila, wiek;
            plik >> gatunek >> x >> y >> sila >> wiek;

            Organizm* nowyOrg = nullptr;
            if (gatunek == "Wilk") nowyOrg = new Wilk(this, x, y, sila, 5, wiek);
            else if (gatunek == "Owca") nowyOrg = new Owca(this, x, y, sila, 4, wiek);
            else if (gatunek == "Lis") nowyOrg = new Lis(this, x, y, sila, 7, wiek);
            else if (gatunek == "Zolw") nowyOrg = new Zolw(this, x, y, sila, 1, wiek);
            else if (gatunek == "Antylopa") nowyOrg = new Antylopa(this, x, y, sila, 4, wiek);
            else if (gatunek == "Trawa") nowyOrg = new Trawa(this, x, y, sila, 0, wiek);
            else if (gatunek == "Mlecz") nowyOrg = new Mlecz(this, x, y, sila, 0, wiek);
            else if (gatunek == "Guarana") nowyOrg = new Guarana(this, x, y, sila, 0, wiek);
            else if (gatunek == "Jagody") nowyOrg = new Jagody(this, x, y, sila, 0, wiek);
            else if (gatunek == "Barszcz") nowyOrg = new Barszcz(this, x, y, sila, 0, wiek);
            else if (gatunek == "Czlowiek") {
                int licznik;
                plik >> licznik;
                nowyOrg = new Czlowiek(this, x, y);
                nowyOrg->setSila(sila);
                nowyOrg->zwiekszWiek(wiek);
                static_cast<Czlowiek*>(nowyOrg)->setLicznik(licznik);
            }

            if (nowyOrg) {
                organizmy.push_back(nowyOrg);
                ustawNaPolu(x, y, nowyOrg);
            }
        }
        plik.close();
        dodajKomunikat("Stan gry zostal wczytany!");
    }
}

void Swiat::upieknienieDol(){
    std::cout << std::endl;
    std::cout << "******************************************************" << std::endl;
    std::cout << "*                                                    *" << std::endl;
    std::cout << "*  STRZALKI - Ruch | U - Umiejetnosc | ESC - Koniec  *" << std::endl;
    std::cout << "*         Z - Zapisz gre | W - Wczytaj gre           *" << std::endl;
    std::cout << "*                                                    *" << std::endl;
    std::cout << "******************************************************" << std::endl;
}