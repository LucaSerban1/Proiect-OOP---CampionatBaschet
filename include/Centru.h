//
// Created by Luca on 5/24/2025.
//

#ifndef CENTRU_H
#define CENTRU_H

#pragma once
#include "Jucator.h"

class Centru : public Jucator {
private:
    std::string Calitate;

public:
    Centru(const std::string& nume, int varsta, int rating, double mediePuncteMeci, const std::string& calitate);
    int Performanta(int puncte) const override;
};


#endif //CENTRU_H
