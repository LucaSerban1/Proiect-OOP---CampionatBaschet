//
// Created by Luca on 5/24/2025.
//

#include "Campionat.h"

void Campionat::adaugaEchipa(const std::shared_ptr<Echipa>& echipa) {
    echipe.push_back(echipa);
}

int Campionat::getPunctetotal() { return punctetotal; }
void Campionat::setPunctetotal(int puncte1, int puncte2) { punctetotal = puncte1+puncte2; }
int Campionat::punctetotal = 0;

const std::vector<std::shared_ptr<Echipa>>& Campionat::getEchipe() const {
    return echipe;
}

std::shared_ptr<Echipa> Campionat::getEchipaDupaNume(const std::string& nume)const{
    for (const auto& echipa : echipe)
    {
        if (echipa->getNume() == nume) {
            return echipa;
        }
    }
    return nullptr;
}

void Campionat::genereazaMeciuri() {
    for (size_t i = 0; i < echipe.size(); ++i) {
        for (size_t j = i + 1; j < echipe.size(); ++j) {
            meciuri.push_back(std::make_shared<MeciDeLiga>(echipe[i], echipe[j]));
        }
    }
}

void Campionat::simuleazaCampionat() {
    int runda = 1;
    for (auto& meci : meciuri) {
        std::cout << "\n--- Runda " << runda++ << " ---\n";
        meci->Simuleaza();
    }
}

void Campionat::afiseazaClasament() {
    std::cout << "\n--- Clasament final ---\n";
    std::sort(echipe.begin(), echipe.end(), [](const std::shared_ptr<Echipa>& e1, const std::shared_ptr<Echipa>& e2) {
        return e1->getPuncteCampionat() > e2->getPuncteCampionat();
    });
    for (const auto& echipa : echipe) {
        std::cout << echipa->getNume() << " - " << echipa->getPuncteCampionat()
                  << " victorii si " << echipe.size() - echipa->getPuncteCampionat() - 1 << " pierderi.\n";
    }
}
