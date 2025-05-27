//
// Created by Luca on 5/24/2025.
//

#include "Echipa.h"
#include <Statistica.h>
#include "Jucator.h"
#include "Fundas.h"
#include "Extrema.h"
#include "Centru.h"
#include "Campionat.h"
#include "DateInvalide.h"
#include <iostream>

Echipa::Echipa() = default;

Echipa::Echipa(const std::string& nume)
    : Nume(nume) {}


// Statistica<int> Echipa::getStatisticaPuncte() { return statisticaPuncte; }
// Statistica<std::string> Echipa::getStatisticaMvpJucatori() { return statisticaMvpJucatori; }

const std::vector<std::shared_ptr<Jucator>> &Echipa::getJucatori() const { return j; }

const std::string& Echipa::getNume() const { return Nume; }

void Echipa::setNume(std::string nume) { Nume = std::move(nume); }

int Echipa::getPuncteCampionat() const { return PuncteCampionat; }

void Echipa::setPuncteCampionat(int puncte) { PuncteCampionat = puncte; }



void Echipa::adaugaJucator(const std::shared_ptr<Jucator> &jucator) { j.push_back(jucator); }

std::shared_ptr<Jucator> Echipa::getJucatorDupaNume(const std::string &nume)
{
    for (const auto &jucator : j)
    {
        if (jucator->getNume() == nume)
        {
            return jucator;
        }
    }
    return nullptr;
    Campionat c1;
    c1.adaugaEchipa(std::make_shared<Echipa>(*this));
}

std::pair<int, std::string> Echipa::SimuleazaMeci() const
{
    int punctemeci = 0, perfmax = 0;
    std::string MVP;

    for (const auto &jucator : j)
    {
        int pmj = jucator->SimuleazaPuncteMeci();
        punctemeci += pmj;
        int perf = jucator->Performanta(pmj);
        if (perf > perfmax)
        {
            perfmax = perf;
            MVP = jucator->getNume();
        }
    }

    std::cout << "Echipa " << Nume << " a marcat " << punctemeci << " puncte in meci.\n";
    return {punctemeci, MVP};
}

void Echipa::adaugaScorMeci(int scor) { statisticaPuncte.adaugaValoare(scor); }
void Echipa::adaugaMvpJucator(const std::string &nume) { statisticaMvpJucatori.adaugaValoare(nume); }

void Echipa::afiseazaStatisticaPuncte() const
{
    std::cout << "Statistica puncte:\n";
    for (const auto &valoare : statisticaPuncte.getValorint())
    {
        std::cout << valoare << ", ";
    }
    std::cout << "\n";
}

void Echipa::afiseazaStatisticaMvpJucatori() const
{
    std::cout << "Statistica MVP Jucatori:\n";
    for (const auto &valoare : statisticaMvpJucatori.getValoriString())
    {
        std::cout << valoare << " ";
    }
    std::cout << "\n";
}

std::istream &operator>>(std::istream &in, Echipa &e)
{
    std::string nume;
    std::cout << "Numele echipei: ";
    std::getline(in >> std::ws, nume);
    e.setNume(nume);

    int nrjucatori;
    std::cout << "Numar jucatori: ";
    in >> nrjucatori;
    try
    {
        if (nrjucatori < 1 || nrjucatori > 10)
        {
            throw DateInvalide();
        }
    }
    catch (const DateInvalide &ex)
    {
        std::cerr << ex.what() << "\n";
        return in;
    }

    for (int i = 0; i < nrjucatori; ++i)
    {
        std::string numejucator, pozitie, calitate;
        int varsta, rating;
        float ppg;

        std::cout << "Introdu numele jucatorului " << i + 1 << ": ";
        std::getline(in >> std::ws, numejucator);

        std::cout << "Pozitia (Fundas/Extrema/Centru): ";
        std::getline(in >> std::ws, pozitie);
        try
        {
            if (pozitie != "Fundas" && pozitie != "Extrema" && pozitie != "Centru")
            {
                throw DateInvalide();
            }
        }
        catch (const DateInvalide &ex)
        {
            std::cerr << ex.what() << "\n";
            --i;
            continue;
        }

        std::cout << "Varsta: ";
        in >> varsta;
        try
        {
            if (varsta < 18 || varsta > 40)
            {
                throw DateInvalide();
            }
        }
        catch (const DateInvalide &ex)
        {
            std::cerr << ex.what() << "\n";
            --i;
            continue;
        }

        std::cout << "Rating (trebuie sa fie intre 1 si 5): ";
        in >> rating;
        try
        {
            if (rating < 1 || rating > 5)
            {
                throw DateInvalide();
            }
        }
        catch (const DateInvalide &ex)
        {
            std::cerr << ex.what() << "\n";
            --i;
            continue;
        }

        std::cout << "Medie puncte pe meci: ";
        in >> ppg;

        if (pozitie == "Fundas")
        {
            std::cout << "Calitate poate fi Playmaker sau Perimeter Defence: ";
            std::getline(in >> std::ws, calitate);
            try
            {
                if (calitate != "Playmaker" && calitate != "Perimeter Defence")
                {
                    throw DateInvalide();
                }
            }
            catch (const DateInvalide &ex)
            {
                std::cerr << ex.what() << "\n";
                --i;
                continue;
            }
        }
        else if (pozitie == "Extrema")
        {
            std::cout << "Calitate poate fi Interior Defence sau Perimeter Defence: ";
            std::getline(in >> std::ws, calitate);
            try
            {
                if (calitate != "Interior Defence" && calitate != "Perimeter Defence")
                {
                    throw DateInvalide();
                }
            }
            catch (const DateInvalide &ex)
            {
                std::cerr << ex.what() << "\n";
                --i;
                continue;
            }
        }
        else if (pozitie == "Centru")
        {
            std::cout << "Calitate poate fi Interior Defence sau Rebounder: ";
            std::getline(in >> std::ws, calitate);
            try
            {
                if (calitate != "Rebounder" && calitate != "Interior Defence")
                {
                    throw DateInvalide();
                }
            }
            catch (const DateInvalide &ex)
            {
                std::cerr << ex.what() << "\n";
                --i;
                continue;
            }
        }

        std::shared_ptr<Jucator> jucator;
        if (pozitie == "Fundas")
            jucator = std::make_shared<Fundas>(numejucator, varsta, rating, ppg, calitate);
        else if (pozitie == "Extrema")
            jucator = std::make_shared<Extrema>(numejucator, varsta, rating, ppg, calitate);
        else if (pozitie == "Centru")
            jucator = std::make_shared<Centru>(numejucator, varsta, rating, ppg, calitate);

        if (jucator != nullptr)
            e.adaugaJucator(jucator);
        else
            --i;
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, const std::shared_ptr<Echipa> &e)
{
    out << "Nume echipa: " << e->getNume() << "\n";
    out << "Jucatori:\n";
    for (const auto &jucator : e->getJucatori())
    {
        out << jucator->getNume() << " are rating " << jucator->getRating()
            << " si inscrie " << jucator->getMediePuncteMeci() << " puncte pe meci.\n";
    }
    return out;
}
