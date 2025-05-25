// #include <iostream>
// #include <array>
//
// int main() {
//     std::cout << "Hello, world!\n";
//     std::array<int, 100> v{};
//     int nr;
//     std::cout << "Introduceți nr: ";
//     /////////////////////////////////////////////////////////////////////////
//     /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
//     /// dați exemple de date de intrare folosind fișierul tastatura.txt
//     /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
//     /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
//     /// De asemenea, trebuie să adăugați în acest fișier date de intrare
//     /// pentru cât mai multe ramuri de execuție.
//     /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
//     /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
//     ///
//     /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
//     /// pentru a simula date introduse de la tastatură.
//     /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
//     ///
//     /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
//     /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
//     /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
//     /// program care merg (și să le evitați pe cele care nu merg).
//     ///
//     /////////////////////////////////////////////////////////////////////////
//     std::cin >> nr;
//     /////////////////////////////////////////////////////////////////////////
//     for(int i = 0; i < nr; ++i) {
//         std::cout << "v[" << i << "] = ";
//         std::cin >> v[i];
//     }
//     std::cout << "\n\n";
//     std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
//     for(int i = 0; i < nr; ++i) {
//         std::cout << "- " << v[i] << "\n";
//     }
//     ///////////////////////////////////////////////////////////////////////////
//     /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
//     /// alt fișier propriu cu ce alt nume doriți.
//     /// Exemplu:
//     /// std::ifstream fis("date.txt");
//     /// for(int i = 0; i < nr2; ++i)
//     ///     fis >> v2[i];
//     return 0;
// }


#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include "json.hpp"
#include "include/Jucator.h"
#include "include/Fundas.h"
#include "include/Extrema.h"
#include "include/Centru.h"
#include "include/Echipa.h"
#include "include/Campionat.h"
#include "include/DateInvalide.h"

using json = nlohmann::json;

int main() {

    std::ifstream fin("D:/Proiect-OOP---CampionatBaschet/echipe.json");
    if (!fin.is_open()) {
        std::cout << "Nu s-a putut deschide fisierul JSON!\n";
        return 0;
    }

    json jEchipe;
    fin >> jEchipe;

    Campionat c1;
    int ok=1;
    int Alegeri = 0;
    while (ok==1) {
        std::cout << "Ce vrei sa faci?\n";
        std::cout << "Adauga numarul de echipe: 1\n";
        std::cout << "Simuleaza campionatul: 2\n";
        std::cout << "Afiseaza clasamentul: 3\n";
        std::cout << "Afiseaza echipele: 4\n";
        std::cout << "Introdu manual o echipa: 5\n";
        std::cout << "Comparare jucatori din aceeasi echipa: 6\n";
        std::cout << "Iesire: 7\n";
        std::cin >> Alegeri;
        if (Alegeri == 1) {
            int numarEchipe = 0;
            std::cout << "Cate echipe vrei sa introduci? ";
            std::cin >> numarEchipe;
            for (int i = 0; i < numarEchipe; ++i) {
                std::string numeEchipa = jEchipe[i].value("nume", "Fara Nume");
                Echipa e(numeEchipa);
                for (const auto& jucator : jEchipe[i]["jucatori"]) {
                    std::string tip = jucator.value("tip", "Fundas");
                    std::string nume = jucator.value("nume", "Anonim");
                    int varsta = jucator.value("varsta", 0);
                    int experienta = jucator.value("rating", 0);
                    float medie = jucator.value("ppg", 0.0f);
                    std::string rol = jucator.value("calitate", "Playmaker");

                    std::shared_ptr<Jucator> j;
                    if (tip == "Fundas")
                        j = std::make_shared<Fundas>(nume, varsta, experienta, medie, rol);
                    else if (tip == "Extrema")
                        j = std::make_shared<Extrema>(nume, varsta, experienta, medie, rol);
                    else if (tip == "Centru")
                        j = std::make_shared<Centru>(nume, varsta, experienta, medie, rol);
                    e.adaugaJucator(j);
                }
                c1.adaugaEchipa(std::make_shared<Echipa>(e));
            }
        }
        if (Alegeri == 2) {
            c1.genereazaMeciuri();
            c1.simuleazaCampionat();
        }
        if (Alegeri == 3)
            c1.afiseazaClasament();
            
        if (Alegeri == 4) {
            for (const auto& e: c1.getEchipe()) {
                std::cout << e << "\n";
            }
        }
        if (Alegeri == 5) {
            Echipa e1;
            std::cin >> e1;
            e1.setPuncteCampionat(0);
            c1.adaugaEchipa(std::make_shared<Echipa>(e1));
        }
        if (Alegeri ==6)
        {
            std::string numeEchipa1;
            std::cout << "Introdu numele echipei: ";
            std::getline(std::cin >> std::ws, numeEchipa1);
            std::shared_ptr<Echipa> e1;
            try{
                bool found = false;
                for(const auto& e : c1.getEchipe()) {
                    if(numeEchipa1 == e->getNume()){
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    throw DateInvalide();
                }   
            } catch (const DateInvalide& ex) {
                std::cerr << ex.what() << "\n";
                continue;
            }
            std::shared_ptr<Jucator> j1;
            std::shared_ptr<Jucator> j2;
            std::cout << "Introdu numele primului jucator: ";
            std::string numeJucator1;
            std::getline(std::cin >> std::ws, numeJucator1);
            try{
                bool found = false;
                for(const auto& jucator : e1->getJucatori()) {
                    if(numeJucator1 == jucator->getNume()){
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    throw DateInvalide();
                }   
            } catch (const DateInvalide& ex) {
                std::cerr << ex.what() << "\n";
                continue;
            }
            std::cout << "Introdu numele celui de-al doilea jucator: ";
            std::string numeJucator2;
            std::getline(std::cin >> std::ws, numeJucator2);
            try{
                bool found = false;
                for(const auto& jucator : e1->getJucatori()) {
                    if(numeJucator2 == jucator->getNume()){
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    throw DateInvalide();
                }   
            } catch (const DateInvalide& ex) {
                std::cerr << ex.what() << "\n";
                continue;
            }
            std::shared_ptr<Jucator> jucator1 = e1->getJucatorDupaNume(numeJucator1);
            std::shared_ptr<Jucator> jucator2 = e1->getJucatorDupaNume(numeJucator2);
            if (jucator1 < jucator2)std::cout << "Jucatorul " << jucator1->getNume() << " este mai bun decat " << jucator2->getNume() << "\n";
            else if (jucator1 > jucator2)std::cout << "Jucatorul " << jucator2->getNume() << " este mai bun decat " << jucator1->getNume() << "\n";
            else std::cout << "Jucatorii sunt egali ca performanta.\n";
        }
        if (Alegeri == 7) {
            std::cout << "In acest campionat s-au inscris " << c1.getPunctetotal() << " puncte.\n";
            std::cout << "Ai simulat campionatul cu succes!\n";
            ok=0;
        }
    }
    return 0;
}