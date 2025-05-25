//
// Created by Luca on 5/24/2025.
//
#include "VarstaInvalida.h"

const char* VarstaInvalida::what() const noexcept {
    return "Varsta jucatorului trebuie sa fie de cel putin 18 ani!";
}
