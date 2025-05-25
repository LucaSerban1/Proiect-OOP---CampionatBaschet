//
// Created by Luca on 5/24/2025.
//

#ifndef ECHIPA_H
#define ECHIPA_H

#pragma once


#include <string>
#include <vector>
#include <memory>
#include "Jucator.h"
#include <Statistica.h>


class Echipa {
private:
    std::string Nume;
    std::vector<std::shared_ptr<Jucator>> j;
    int PuncteCampionat;
    Statistica<int> statisticaPuncte;
    Statistica<std::string> statisticaMvpJucatori;
    static int punctetotal;
public:
    Echipa();
    Echipa(const std::string& nume);
    const std::vector<std::shared_ptr<Jucator>>& getJucatori() const;
    std::string getNume() const;
    void setNume(std::string nume);
    int getPuncteCampionat() const;
    void setPuncteCampionat(int puncte);
    void adaugaJucator(const std::shared_ptr<Jucator>& jucator);
    std::shared_ptr<Jucator> getJucatorDupaNume(const std::string& nume);
    Statistica<int> getStatisticaPuncte() ;
    Statistica<std::string> getStatisticaMvpJucatori() ;

    void afiseazaEchipa() const;
    std::pair<int, std::string> SimuleazaMeci() const;

    void adaugaScorMeci(int scor);
    void adaugaMvpJucator(const std::string& nume);

    void afiseazaMvpMeci();
    void afiseazaPuncteMeci();  

    friend std::istream& operator>>(std::istream& in, Echipa& e);
    friend std::ostream& operator<<(std::ostream& out, const std::shared_ptr<Echipa> &e);

    virtual ~Echipa() = default;
};

#endif //ECHIPA_H
