#pragma once
#include <iostream>
#include "Organizm.h"
#include <vector>
#include <fstream>

class Organizm;

class Swiat {
private:
    static const int N = 20;
    static const int M = 20;
    Organizm* plansza[N][M];
    std::vector<Organizm*> organizmy;
    void sprzataczka();
    int nastepnyRuch = -1;
    std::vector<std::string> komunikaty;
public:
    void dodajKomunikat(std::string s);
    Swiat();
    void rysujSwiat();
    void ustawNaPolu(int x, int y, Organizm* o);
    Organizm* getZPola(int x, int y);
    void dodajOrganizm(Organizm* o);
    void wykonajTure();
    void setNastepnyRuch(int r);
    void moby();
    void zapiszSwiat();
    void wczytajSwiat();
    void upieknienieDol();
};