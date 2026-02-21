#ifndef SEURAAJA_H
#define SEURAAJA_H
#include <string>

class Seuraaja
{
public:
    Seuraaja* next; //pointteri seuraavaan seuraajaan linkitetyssä listassa
    Seuraaja(std::string); //konstruktori
    std::string getNimi(); //palauttaa seuraajan nimen
    void paivitys(std::string); //tulostaa konsolille saatu viesti

private:
    std::string nimi; //seuraajan nimi
};


#endif // SEURAAJA_H
