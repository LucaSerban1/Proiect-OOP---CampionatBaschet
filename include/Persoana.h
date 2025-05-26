//
// Created by Luca on 5/24/2025.
//

#ifndef PERSOANA_H
#define PERSOANA_H

#pragma once
#include <string>

class Persoana {
protected:
    std::string Nume = "";
    int Varsta;
public:
    Persoana(const std::string& nume, int varsta);
    virtual ~Persoana() = default;
};

#endif //PERSOANA_H
