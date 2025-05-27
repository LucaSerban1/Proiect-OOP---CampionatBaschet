#include "UserInterface.h"


UserInterface::UserInterface(){
    std::ifstream fin("../echipe.json");
    if (!fin.is_open())
    {
        std::cout << "Nu s-a putut deschide fisierul JSON!\n";
    }
    else{
    
    json jEchipe;
    fin >> jEchipe;

    Campionat c1;
    int ok = 1;
    int alegeri =0;
    int nrEchipeTotal = 0;
    while (ok == 1)
    {
        std::cout << "Alege ce vrei sa faci:\n";
        std::cout << "1. Citeste echipe din fisier JSON\n";
        std::cout << "2. Citeste echipe manual\n";
        std::cout << "3. Simuleaza campionatul\n";
        std::cout << "4. Afiseaza echipele\n";
        std::cout << "5. Compara 2 jucatori dintr-o echipa. \n";
        std::cout << "6. Afiseaza statistici pentru o echipa\n";
        std::cout << "7. Simuleaza finala campionatului\n";
        std::cout << "8. Iesi\n";
        std::cin >> alegeri;
        if( alegeri ==1 ){
        std::cout << "Cate echipe vrei sa introduci? ";
        int numarEchipe = 0;
        std::cin >> numarEchipe;
        for (int i = 0; i < numarEchipe; ++i)
        {
            std::string numeEchipa = jEchipe[i+nrEchipeTotal].value("nume", "Fara Nume");
            Echipa e(numeEchipa);
            for (const auto &jucator : jEchipe[i]["jucatori"])
            {
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
        nrEchipeTotal += numarEchipe;
        std::cout << "Echipele au fost adaugate cu succes!\n";
        }
        if(alegeri == 2){
        Echipa e1;
        std::cout << "Introduceti o echipa manual:\n";
        std::cin >> e1;
        e1.setPuncteCampionat(0);
        c1.adaugaEchipa(std::make_shared<Echipa>(e1));
        }
        if(alegeri == 3)
        {
            c1.genereazaMeciuri();
            c1.simuleazaCampionat();
            c1.afiseazaClasament();
        }
        if(alegeri == 4)
        {
            for (const auto &e : c1.getEchipe())
            {
                std::cout << e << "\n";
            }
        }
        if (alegeri == 5){
        std::shared_ptr<Echipa> e1;
        std::string numeEchipa;
        std::cout << "Introduceti numele echipei: ";
        std::getline(std::cin >> std::ws, numeEchipa);
        e1 = c1.getEchipaDupaNume(numeEchipa);
        std::shared_ptr<Jucator> j1;
        std::shared_ptr<Jucator> j2;
        std::cout << "Introdu numele primului jucator: ";
        std::string numeJucator1;
        std::getline(std::cin >> std::ws, numeJucator1);
        std::cout << "Introdu numele celui de-al doilea jucator: ";
        std::string numeJucator2;
        std::getline(std::cin >> std::ws, numeJucator2);
        std::shared_ptr<Jucator> jucator1 = e1->getJucatorDupaNume(numeJucator1);
        std::shared_ptr<Jucator> jucator2 = e1->getJucatorDupaNume(numeJucator2);
        if (jucator1 < jucator2)
            std::cout << "Jucatorul " << numeJucator1 << " este mai bun decat " << numeJucator2 << "\n";
        else if (jucator1 > jucator2)
            std::cout << "Jucatorul " << numeJucator2 << " este mai bun decat " << numeJucator1 << "\n";
        else
            std::cout << "Jucatorii sunt la fel de buni ca performanta.\n";
        }
        if(alegeri == 6){
        std::shared_ptr<Echipa> e1;
        std::cout << "Introduceti numele echipei pentru statistici: ";
        std::string numeEchipa;
        std::getline(std::cin >> std::ws, numeEchipa);
        e1 = c1.getEchipaDupaNume(numeEchipa);
        e1->afiseazaStatisticaPuncte();
        e1->afiseazaStatisticaMvpJucatori();
        }
        if(alegeri == 7)
        {
            std::cout << "Simularea finalei campionatului:\n";
            if (c1.getEchipe().size() < 2) {
                std::cout << "Nu sunt suficiente echipe pentru a simula finala.\n";
                continue;
            }
            std::shared_ptr<Echipa> echipa1 = c1.getEchipe()[0];
            std::shared_ptr<Echipa> echipa2 = c1.getEchipe()[1];
            std::shared_ptr<MeciPlayoff> finala = std::make_shared<MeciPlayoff>(echipa1, echipa2);
            finala->Simuleaza();
            if (finala->getMeciuriCastigate1() > finala->getMeciuriCastigate2()) {
                std::cout << echipa1->getNume() << " a castigat finala!\n";
            } else {
                std::cout << echipa2->getNume() << " a castigat finala!\n";
            }
        }
        if(alegeri == 8){
        std::cout << "In acest campionat s-au inscris " << c1.getPunctetotal() << " puncte.\n";
        std::cout << "Ai simulat campionatul cu succes!\n";
        Campionat c2;
        c2.adaugaEchipa(std::shared_ptr<Echipa>(nullptr));
        c2.adaugaEchipa(std::shared_ptr<Echipa>(nullptr));
        c2.genereazaMeciuri();
        ok = 0;
        }
    }
    Echipa e2;
    Campionat c2;
    c2.adaugaEchipa(std::make_shared<Echipa>(e2));
    }
    fin.close();
}