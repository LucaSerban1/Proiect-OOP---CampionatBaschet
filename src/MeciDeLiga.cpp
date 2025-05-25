//
// Created by Luca on 5/24/2025.
//
#include "MeciDeLiga.h"
#include <iostream>

MeciDeLiga::MeciDeLiga(const std::shared_ptr<Echipa>& echipa1, const std::shared_ptr<Echipa>& echipa2)
    : Meci(echipa1, echipa2) {}

void MeciDeLiga::Simuleaza() {
    std::cout << "Echipa: " << Echipa1->getNume() << " joaca impotriva echipei: " << Echipa2->getNume() << "\n";

    auto [puncteechipa1, MVPechipa1] = Echipa1->SimuleazaMeci();
    std::cout << "\n";
    auto [puncteechipa2, MVPechipa2] = Echipa2->SimuleazaMeci();

    if (puncteechipa1 > puncteechipa2) {
        std::cout << Echipa1->getNume() << " a castigat meciul cu scorul de " << puncteechipa1 << " - " << puncteechipa2 << "!\n";
        std::cout << "Mvp-ul meciului este " << MVPechipa1 << "!\n";
        int pct = Echipa1->getPuncteCampionat() + 1;
        Echipa1->setPuncteCampionat(pct);
    }
    else if (puncteechipa1 < puncteechipa2) {
        std::cout << Echipa2->getNume() << " a castigat meciul cu scorul de " << puncteechipa2 << " - " << puncteechipa1 << "!\n";
        std::cout << "Mvp-ul meciului este " << MVPechipa2 << "!\n";
        int pct = Echipa2->getPuncteCampionat() + 1;
        Echipa2->setPuncteCampionat(pct);
    }
    else {
        std::cout << "Echipa " << Echipa1->getNume() << " si " << Echipa2->getNume() << " au avut acelasi scor! Meciul trebuie reluat!\n";
    }
}
