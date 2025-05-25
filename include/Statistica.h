//
// Created by Luca on 5/25/2025.
//

#ifndef STATISTICA_H
#define STATISTICA_H

#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Statistica {
private:
    std::vector<T> valori;

public:
    void adaugaValoare(const T& valoare) {
        valori.push_back(valoare);
    }

    int getDimensiune() const {
        return static_cast<int>(valori.size());
    }

    const std::vector<T>& getValori() const {  
        return valori;
    }
};


#endif //STATISTICA_H