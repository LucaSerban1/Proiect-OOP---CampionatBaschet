//
// Created by Luca on 5/24/2025.
//
#include "DateInvalide.h"

class DateInvalide : public std::exception {
public:
    const char* what() const noexcept override {
        return "Date invalide: valoarea trebuie să fie pozitivă.";
    }
};
