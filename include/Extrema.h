//
// Created by Luca on 5/24/2025.
//

#ifndef EXTREMA_H
#define EXTREMA_H

#pragma once
#include "Jucator.h"

class Extrema : public Jucator {
private:
    std::string Calitate = "";
public:
    Extrema(const std::string& nume, int varsta, int rating, double mediePuncteMeci, const std::string& calitate);
    int Performanta(int puncte) const override;
};


#endif //EXTREMA_H
