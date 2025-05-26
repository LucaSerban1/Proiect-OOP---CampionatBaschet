//
// Created by Luca on 5/24/2025.
//

#include "Fundas.h"
#include <iostream>

Fundas::Fundas(const std::string& nume, int varsta, int rating, double mediePuncteMeci, const std::string& calitate)
    : Jucator(nume, varsta, rating, mediePuncteMeci), Calitate(calitate) {}

int Fundas::Performanta(int puncte) const {
    int assists = 0, steals = 0;

    if (Calitate == "Playmaker") {
        assists = static_cast<int>(SimuleazaPaseDecisiveMeci() * 1.3);
        steals = SimuleazaStealsMeci();
    } else if (Calitate == "Perimeter Defence") {
        steals = static_cast<int>(SimuleazaStealsMeci() * 1.3);
        assists = SimuleazaPaseDecisiveMeci();
    }

    std::cout << Nume << " a inregistrat si " << puncte
              << " puncte, " << assists << " assisturi si "
              << steals << " stealuri.\n";

    return puncte + assists + steals;
}
