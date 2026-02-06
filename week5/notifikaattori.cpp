#include "notifikaattori.h"
#include <iostream>

Notifikaattori::Notifikaattori()
{
    std::cout << "Luodaan notifikaattori" << std::endl;
}

void Notifikaattori::lisaa(Seuraaja* uusiSeur)
{
    uusiSeur->next = seuraajat; //linkittää uuden seuraajan nykyiseen seuraajaan
    seuraajat = uusiSeur; //siirtää seuraajan uuteen seuraajaan
    std::cout << "Notifikaattori lisaa seuraajan " << uusiSeur->getNimi() << std::endl;
}

void Notifikaattori::poista(Seuraaja * target)
{
    if (seuraajat == target) { //Poistaa head/alku seuraajan (jos yritettäisiin poistaa &c main()issa)
        std::cout << "Notifikaattori poistaa seuraajan " << target->getNimi() << std::endl;
        seuraajat = seuraajat->next;
        return;
    }
    Seuraaja* prev = seuraajat; //tarvitaan 2 pointteria; edellinen ja nykyinen
    Seuraaja* curr = seuraajat->next;

    while (curr != nullptr)
    {
        if (curr == target) {
            std::cout << "Notifikaattori poistaa seuraajan " << target->getNimi() << std::endl;
            prev->next = curr->next; //muokataan A-> next osoittamaan C:hen
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}

void Notifikaattori::tulosta() //Tulostaa koko seuraajalistan
{
    Seuraaja* curr = seuraajat; //alku

    std::cout << "Notifikaattorin seuraajat:" << std::endl;

    while (curr != nullptr)
    {
        std::cout << "Seuraaja " << curr->getNimi() << std::endl;
        curr = curr->next; //siirrytään eteenpäin
    }
}

void Notifikaattori::postita(std::string viesti)
{
    Seuraaja* curr = seuraajat;

    std::cout << "Notifikaattori postaa viestin: " << viesti << std::endl;

    while (curr != nullptr)
    {
        curr->paivitys(viesti);
        curr = curr->next;
    }
}
