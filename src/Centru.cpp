//
// Created by Luca on 5/24/2025.
//

#include "Centru.h"
#include <iostream>

Centru::Centru(const std::string& nume, int varsta, int rating, double mediePuncteMeci, const std::string& calitate)
    : Jucator(nume, varsta, rating, mediePuncteMeci), Calitate(calitate) {}

int Centru::Performanta(int puncte) const {
    int blocks = 0, rebounds = 0;

    if (Calitate == "Interior Defence") {
        blocks = static_cast<int>(SimuleazaBlocksMeci() * 1.3);
        rebounds = SimuleazaReboundsMeci();
    }
    else if (Calitate == "Rebounder") {
        blocks = SimuleazaBlocksMeci();
        rebounds = static_cast<int>(SimuleazaReboundsMeci() * 1.3);
    }

    std::cout << Nume << " a inregistrat si " << puncte << " puncte, "
              << rebounds << " rebounduri si " << blocks << " blockuri.\n";

    return puncte + blocks + rebounds;
}
