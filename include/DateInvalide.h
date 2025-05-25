//
// Created by Luca on 5/24/2025.
//

#ifndef DATEINVALIDE_H
#define DATEINVALIDE_H

#pragma once
#include <exception>

class DateInvalide : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif //DATEINVALIDE_H
