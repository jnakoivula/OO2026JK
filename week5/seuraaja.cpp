#include "seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(std::string s) : nimi(s), next(nullptr)
{
    std::cout << "Luodaan seuraaja " << nimi << std::endl;
}

std::string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(std::string p)
{
    std::cout << "Seuraaja " << nimi << " sai viestin: " << p << std::endl;
}
