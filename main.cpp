#include "Swiat.h"
#include "Organizm.h"
#include "Czlowiek.h"
#include <conio.h>
#include <iostream>

int main() { 
    srand(time(NULL));
    Swiat swiat;
    swiat.moby();

    while(true){
    system("cls");
    std::cout << "Oliwier Maziarz, ######" << std::endl;
    swiat.rysujSwiat();
    swiat.upieknienieDol();
        int klawisz = _getch(); 

        if (klawisz == 224) { 
            int strzalka = _getch();
            if (strzalka == 72) swiat.setNastepnyRuch(0); 
            else if (strzalka == 80) swiat.setNastepnyRuch(1); 
            else if (strzalka == 75) swiat.setNastepnyRuch(2); 
            else if (strzalka == 77) swiat.setNastepnyRuch(3);
            swiat.wykonajTure();
        } 
        else if (klawisz == 'u' || klawisz == 'U') {
            swiat.setNastepnyRuch(4);
            swiat.wykonajTure();
        }
        else if (klawisz == 'z' || klawisz == 'Z') {
            swiat.zapiszSwiat();
        }
        else if (klawisz == 'w' || klawisz == 'W') {
            swiat.wczytajSwiat();
        }
        else if (klawisz == 27) break;
    }
    return 0;
}
