//
// Created by Luca on 5/24/2025.
//

#ifndef CAMPIONAT_H
#define CAMPIONAT_H

#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include "Echipa.h"
#include "MeciDeLiga.h"

class Campionat {
private:
    std::vector<std::shared_ptr<Echipa>> echipe;
    std::vector<std::shared_ptr<Meci>> meciuri;
    static int punctetotal;

public:
    Campionat() = default;
    int getPunctetotal();
    static void setPunctetotal(int puncte1, int puncte2);
    void adaugaEchipa(const std::shared_ptr<Echipa>& echipa);
    const std::vector<std::shared_ptr<Echipa>>& getEchipe() const;
    std::shared_ptr<Echipa> getEchipaDupaNume(const std::string& nume) const;
    int getNrMeciuri(std::vector<std::shared_ptr<Meci>> meciuri) const;

    void genereazaMeciuri();
    void simuleazaCampionat();
    void afiseazaClasament();

    ~Campionat() = default;
};

#endif //CAMPIONAT_H
