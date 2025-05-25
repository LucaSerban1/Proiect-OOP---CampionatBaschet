//
// Created by Luca on 5/24/2025.
//

#ifndef VARSTAINVALIDA_H
#define VARSTAINVALIDA_H

#pragma once
#include <exception>

class VarstaInvalida : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif //VARSTAINVALIDA_H
