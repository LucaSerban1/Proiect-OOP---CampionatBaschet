//
// Created by Luca on 5/24/2025.
//

#ifndef FUNDAS_H
#define FUNDAS_H

#include "Jucator.h"
#include <string>
#pragma once


class Fundas : public Jucator {
private:
    std::string Calitate = "";

public:
    Fundas(const std::string& nume, int varsta, int rating, double mediePuncteMeci, const std::string& calitate);
    int Performanta(int puncte) const override;
};

#endif // FUNDAS_H
