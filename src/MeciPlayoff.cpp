//
// Created by Luca on 5/24/2025.
//

#include "MeciPlayoff.h"
#include <iostream>

MeciPlayoff::MeciPlayoff(const std::shared_ptr<Echipa>& echipa1, const std::shared_ptr<Echipa>& echipa2)
    : Meci(echipa1, echipa2) {
    MeciuriCastigate1 = 0;
    MeciuriCastigate2 = 0;
    }

int MeciPlayoff::getMeciuriCastigate1() {
    return MeciuriCastigate1;
}

int MeciPlayoff::getMeciuriCastigate2() {
    return MeciuriCastigate2;
}

void MeciPlayoff::setMeciuriCastigate1(int meciuri) {
    MeciuriCastigate1 = meciuri;
}

void MeciPlayoff::setMeciuriCastigate2(int meciuri) {
    MeciuriCastigate2 = meciuri;
}

void MeciPlayoff::Simuleaza() {
    std::cout << "Echipa: " << Echipa1->getNume() << " joaca impotriva echipei: " << Echipa2->getNume() << "\n";

    int nrMeci = 0;
    while (getMeciuriCastigate1() != 4 && getMeciuriCastigate2() != 4) {
        nrMeci++;
        auto [puncteechipa1, MVPechipa1] = Echipa1->SimuleazaMeci();
        std::cout << "\n";
        auto [puncteechipa2, MVPechipa2] = Echipa2->SimuleazaMeci();

        if (puncteechipa1 > puncteechipa2) {
            std::cout << Echipa1->getNume() << " a castigat meciul " << nrMeci << " cu scorul de " << puncteechipa1 << " - " << puncteechipa2 << "!\n";
            std::cout << "Mvp-ul meciului este " << MVPechipa1 << "!\n";
            setMeciuriCastigate1(getMeciuriCastigate1() + 1);
        }
        else if (puncteechipa1 < puncteechipa2) {
            std::cout << Echipa2->getNume() << " a castigat meciul " << nrMeci << " cu scorul de " << puncteechipa2 << " - " << puncteechipa1 << "!\n";
            std::cout << "Mvp-ul meciului este " << MVPechipa2 << "!\n";
            setMeciuriCastigate2(getMeciuriCastigate2() + 1);
        }
    }

    if (MeciuriCastigate1 > MeciuriCastigate2) {
        std::cout << Echipa1->getNume() << " trece mai departe, a castigat seria cu scorul de " << MeciuriCastigate1 << " - " << MeciuriCastigate2 << "!\n";
    }
    else {
        std::cout << Echipa2->getNume() << " trece mai departe, a castigat seria cu scorul de " << MeciuriCastigate2 << " - " << MeciuriCastigate1 << "!\n";
    }
}
