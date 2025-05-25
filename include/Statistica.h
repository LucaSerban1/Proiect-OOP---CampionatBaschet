//
// Created by Luca on 5/25/2025.
//

#ifndef STATISTICA_H
#define STATISTICA_H

#pragma once
#include <iostream>
#include <vector>

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

    std::vector<int> getValorint() const {
        return valori;
    }

    std::vector<std::string> getValoriString(){
        return valori;}
};


#endif //STATISTICA_H