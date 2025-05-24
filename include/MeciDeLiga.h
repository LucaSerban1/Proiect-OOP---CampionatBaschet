//
// Created by Luca on 5/24/2025.
//

#ifndef MECIDELIGA_H
#define MECIDELIGA_H

#pragma once
#include <memory>
#include "Meci.h"   // presupunem că clasa de bază Meci este definită aici

class MeciDeLiga : public Meci {
public:
    MeciDeLiga(const std::shared_ptr<Echipa>& echipa1, const std::shared_ptr<Echipa>& echipa2);
    void Simuleaza() override;
};


#endif //MECIDELIGA_H
