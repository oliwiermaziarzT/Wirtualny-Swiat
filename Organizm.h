#pragma once
#include "Swiat.h"

class Swiat;

class Organizm{
protected:
    int x, y;
    Swiat* swiat;
    int sila;
    int inicjatywa;
    int wiek;
    bool alive = true;
    int tura;
public:
    Organizm(Swiat* swiat, int x, int y, int sila, int inicjatywa, int wiek): 
    swiat(swiat), x(x), y(y), sila(sila), inicjatywa(inicjatywa), wiek(wiek) {}
    virtual ~Organizm() {}
    virtual void rysowanie()=0;
    int getX();
    int getY();
    int getSila();
    int getInicjatywa();
    int getWiek();
    int zwiekszWiek(int wartosc=1);
    int setX(int x);
    int setY(int x);
    virtual void akcja()=0;
    virtual void kolizja(Organizm* inny)=0;
    bool isAlive();
    void kill();
    virtual std::string getGatunek()=0;
    virtual Organizm* nowy(int x, int y)=0;
    int wzmocnienie(int value);
    void setSila(int sila);
    void setWiek(int wiek);
};