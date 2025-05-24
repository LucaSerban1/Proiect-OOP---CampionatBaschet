//
// Created by Luca on 5/24/2025.
//

#ifndef MECI_H
#define MECI_H

#pragma once

#include <memory>
#include "Echipa.h"

class Meci {
protected:
    std::shared_ptr<Echipa> Echipa1;
    std::shared_ptr<Echipa> Echipa2;

public:
    Meci(const std::shared_ptr<Echipa>& echipa1, const std::shared_ptr<Echipa>& echipa2);

    virtual void Simuleaza() = 0;
    virtual ~Meci() = default;
};


#endif //MECI_H
