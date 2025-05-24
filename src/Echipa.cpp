//
// Created by Luca on 5/24/2025.
//

#pragma once
#include "D:/Proiect-OOP---CampionatBaschet/include/Echipa.h"
#include "D:/Proiect-OOP---CampionatBaschet/include/Jucator.h"
#include "D:/Proiect-OOP---CampionatBaschet/include/Fundas.h"
#include "D:/Proiect-OOP---CampionatBaschet/include/Extrema.h"
#include "D:/Proiect-OOP---CampionatBaschet/include/Centru.h"
#include "D:/Proiect-OOP---CampionatBaschet/include/VarstaInvalida.h"
#include <iostream>


Echipa::Echipa() = default;

Echipa::Echipa(const std::string& nume) {
    Nume = nume;
    PuncteCampionat = 0;
}

const std::vector<std::shared_ptr<Jucator>>& Echipa::getJucatori() const {
    return j;
}

std::string Echipa::getNume() const {
    return Nume;
}

void Echipa::setNume(std::string nume) {
    Nume = std::move(nume);
}

int Echipa::getPuncteCampionat() const {
    return PuncteCampionat;
}

void Echipa::setPuncteCampionat(int puncte) {
    PuncteCampionat = puncte;
}

void Echipa::adaugaJucator(const std::shared_ptr<Jucator>& jucator) {
    j.push_back(jucator);
}

void Echipa::afiseazaEchipa() const {
    std::cout << "Echipa: " << Nume << " cu " << j.size() << " jucatori:\n";
    for (const auto& jucator : j) {
        std::cout << jucator->getNume() << " are rating " << jucator->getRating()
                  << " si inscrie " << jucator->getMediePuncteMeci() << " puncte pe meci.\n";
    }
}

std::pair<int, std::string> Echipa::SimuleazaMeci() const {
    int punctemeci = 0, perf = 0, perfmax = 0;
    std::string MVP;

    for (const auto& jucator : j) {
        int pmj = jucator->SimuleazaPuncteMeci();
        punctemeci += pmj;
        perf = jucator->Performanta(pmj);
        if (perf > perfmax) {
            perfmax = perf;
            MVP = jucator->getNume();
        }
    }

    std::cout << "Echipa " << Nume << " a marcat " << punctemeci << " puncte in meci.\n";
    return {punctemeci, MVP};
}

std::istream& operator>>(std::istream& in, Echipa& e) {
    std::string nume;
    std::cout << "Numele echipei: ";
    std::getline(in >> std::ws, nume);
    e.setNume(nume);

    int nrjucatori;
    std::cout << "Numar jucatori: ";
    in >> nrjucatori;

    for (int i = 0; i < nrjucatori; ++i) {
        std::string numejucator, pozitie, calitate;
        int varsta, rating;
        float ppg;

        std::cout << "Introdu numele jucatorului " << i + 1 << ": ";
        std::getline(in >> std::ws, numejucator);

        std::cout << "Pozitia: ";
        std::getline(in >> std::ws, pozitie);

        std::cout << "Varsta: ";
        in >> varsta;

        std::cout << "Rating (trebuie sa fie intre 1 si 5): ";
        in >> rating;

        std::cout << "Medie puncte pe meci: ";
        in >> ppg;

        if (pozitie == "Fundas") std::cout << "Calitate poate fi Playmaker sau Perimeter Defence: ";
        else if (pozitie == "Extrema") std::cout << "Calitate poate fi Interior Defence sau Perimeter Defence: ";
        else if (pozitie == "Centru") std::cout << "Calitate poate fi Interior Defence sau Rebounder: ";

        std::getline(in >> std::ws, calitate);

        std::shared_ptr<Jucator> jucator;
        try {
            if (pozitie == "Fundas")
                jucator = std::make_shared<Fundas>(numejucator, varsta, rating, ppg, calitate);
            else if (pozitie == "Extrema")
                jucator = std::make_shared<Extrema>(numejucator, varsta, rating, ppg, calitate);
            else if (pozitie == "Centru")
                jucator = std::make_shared<Centru>(numejucator, varsta, rating, ppg, calitate);
            else
                throw std::invalid_argument("Pozitia nu este valida!");
        } catch (const std::exception& ex) {
            std::cerr << "Eroare: " << ex.what() << "\n";
        }

        if (jucator != nullptr)
            e.adaugaJucator(jucator);
        else
            --i;
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const std::shared_ptr<Echipa> &e) {
    out << "Nume echipa: " << e->getNume() << "\n";
    out << "Jucatori:\n";
    for (const auto& jucator : e->getJucatori()) {
        out << jucator->getNume() << " are rating " << jucator->getRating()
            << " si inscrie " << jucator->getMediePuncteMeci() << " puncte pe meci.\n";
    }
    return out;
}
