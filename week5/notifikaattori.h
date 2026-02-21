#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H
#include <string>
#include "seuraaja.h"

class Notifikaattori
{
public:
    Notifikaattori();
    void lisaa(Seuraaja *); //lisää seuraajan
    void poista(Seuraaja *); //poistaa seuraajan
    void tulosta(); //tulostaa listan seuraajista
    void postita(std::string); //lähettää viestin kaikille

private:
    Seuraaja* seuraajat = nullptr;
};

#endif // NOTIFIKAATTORI_H
