#include <iostream>
#include "Organizm.h"
#include "Swiat.h"

int Organizm::getX() {
    return x;
}

int Organizm::getY() {

    return y;
}
bool Organizm::isAlive(){
    return alive;
}
void Organizm::kill(){
    alive = false;
}

int Organizm::getSila(){
    return sila;
}

int Organizm::getInicjatywa(){
    return inicjatywa;
}

int Organizm::getWiek(){
    return wiek;
}

int Organizm::zwiekszWiek(int wartosc) {
    return wiek += wartosc;
}

int Organizm::wzmocnienie(int value){
    return sila += value;
}
int Organizm::setX(int x){
    this->x = x;
    return this->x;
}

int Organizm::setY(int y){
    this->y = y;
    return this->y;
}
void Organizm::setSila(int sila){
    this->sila = sila;
}
void Organizm::setWiek(int wiek){
    this->wiek = wiek;
}
