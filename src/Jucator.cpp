//
// Created by Luca on 5/24/2025.
//

#include "Jucator.h"
#include "VarstaInvalida.h"

Jucator::Jucator(const std::string& nume, int varsta, int rating, double mediePuncteMeci)
    : Persoana(nume, varsta){
        rating = rating;
        MediePuncteMeci = mediePuncteMeci;
    if (varsta < 18) throw VarstaInvalida();
}

bool Jucator::SimuleazaSanse() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    int sansa = dist(gen);
    int prag = 0;
    switch (Rating) {
        case 1: prag = 10; break;
        case 2: prag = 20; break;
        case 3: prag = 30; break;
        case 4: prag = 40; break;
        case 5: prag = 50; break;
    }
    return sansa <= prag;
}

int Jucator::SimuleazaPuncteMeci() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    int puncte = MediePuncteMeci;

    if (SimuleazaSanse()) {
        std::uniform_real_distribution<> dist(1.0, 2.0);
        puncte *= dist(gen);
    } else {
        std::uniform_real_distribution<> dist(0.5f, 0.9f);
        puncte *= dist(gen);
    }
    return puncte;
}

int Jucator::SimuleazaPaseDecisiveMeci() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    if (SimuleazaSanse()) {
        std::uniform_int_distribution<> dist(4, 6);
        return dist(gen);
    } else {
        std::uniform_int_distribution<> dist(2, 3);
        return dist(gen);
    }
}

int Jucator::SimuleazaReboundsMeci() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    if (SimuleazaSanse()) {
        std::uniform_int_distribution<> dist(5, 8);
        return dist(gen);
    } else {
        std::uniform_int_distribution<> dist(2, 4);
        return dist(gen);
    }
}

int Jucator::SimuleazaStealsMeci() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    if (SimuleazaSanse()) {
        std::uniform_int_distribution<> dist(4, 6);
        return dist(gen);
    } else {
        std::uniform_int_distribution<> dist(1, 3);
        return dist(gen);
    }
}

int Jucator::SimuleazaBlocksMeci() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    if (SimuleazaSanse()) {
        std::uniform_int_distribution<> dist(4, 6);
        return dist(gen);
    } else {
        std::uniform_int_distribution<> dist(1, 3);
        return dist(gen);
    }
}

std::string Jucator::getNume() const {
    return Nume;
}

int Jucator::getVarsta() const {
    return Varsta;
}

int Jucator::getRating() const {
    return Rating;
}

double Jucator::getMediePuncteMeci() const {
    return MediePuncteMeci;
}

void Jucator::setMediePuncteMeci(double mediePuncteMeci) {
    MediePuncteMeci = mediePuncteMeci;
}
