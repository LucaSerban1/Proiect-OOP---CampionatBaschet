//
// Created by Luca on 5/24/2025.
//

#ifndef JUCATOR_H
#define JUCATOR_H

#include <string>
#include <random>
#include "Persoana.h"
#pragma once

class Jucator : public Persoana {
protected:
    int Rating;
    double MediePuncteMeci;

public:
    Jucator(const std::string& nume, int varsta, int rating, double mediePuncteMeci);

    bool SimuleazaSanse() const;
    int SimuleazaPuncteMeci() const;
    int SimuleazaPaseDecisiveMeci() const;
    int SimuleazaReboundsMeci() const;
    int SimuleazaStealsMeci() const;
    int SimuleazaBlocksMeci() const;

    virtual int Performanta(int puncte) const = 0;

    std::string getNume() const;
    int getVarsta() const;
    int getRating() const;
    double getMediePuncteMeci() const;
    
    friend bool operator<(const Jucator& j1, const Jucator& j2);
};



#endif // JUCATOR_H

