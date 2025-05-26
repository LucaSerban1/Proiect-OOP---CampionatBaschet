//
// Created by Luca on 5/24/2025.
//

#include "Extrema.h"
#include <iostream>

Extrema::Extrema(const std::string& nume, int varsta, int rating, double mediePuncteMeci, const std::string& calitate)
    : Jucator(nume, varsta, rating, mediePuncteMeci), Calitate(calitate) {}

int Extrema::Performanta(int puncte) const {
    int steals = 0, blocks = 0;

    if (Calitate == "Interior Defence") {
        steals = SimuleazaStealsMeci();
        blocks = static_cast<int>(SimuleazaBlocksMeci() * 1.3);
    }
    else if (Calitate == "Perimeter Defence") {
        steals = static_cast<int>(SimuleazaStealsMeci() * 1.3);
        blocks = SimuleazaBlocksMeci();
    }

    std::cout << Nume << " a inregistrat si " << puncte << " puncte, "
              << steals << " stealuri si " << blocks << " blockuri.\n";

    return puncte + blocks + steals;
}
