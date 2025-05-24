//
// Created by Luca on 5/24/2025.
//

#ifndef MECIPLAYOFF_H
#define MECIPLAYOFF_H

#pragma once
#include <memory>
#include "Meci.h"

class MeciPlayoff : public Meci {
private:
    int MeciuriCastigate1;
    int MeciuriCastigate2;

public:
    MeciPlayoff(const std::shared_ptr<Echipa>& echipa1, const std::shared_ptr<Echipa>& echipa2);

    int getMeciuriCastigate1();
    int getMeciuriCastigate2();
    void setMeciuriCastigate1(int meciuri);
    void setMeciuriCastigate2(int meciuri);

    void Simuleaza() override;
};


#endif //MECIPLAYOFF_H
