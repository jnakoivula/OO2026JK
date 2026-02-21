#include "asiakas.h"
#include <iostream>

Asiakas::Asiakas(std::string s, double raja) : nimi(s), kayttotili(s), luottotili(s, raja)
{
    std::cout << "Pankkitili luotu " << nimi << ":lle" << std::endl;
    std::cout << "Luottotili luotu " << nimi << " :lle, luottoraja: " << raja << std::endl;
    std::cout << "Asiakkuus luotu " << nimi << std::endl;
}

std::string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    std::cout << "Kayttotilin saldo: " << kayttotili.getBalance() << std::endl;
    std::cout << "Luottotilin saldo: " << luottotili.getBalance() << ", luottoa jaljella: " << luottotili.nostettavissa() <<  std::endl;
}

bool Asiakas::talletus(double summa)
{
    return kayttotili.deposit(summa);
}

bool Asiakas::nosto(double summa)
{
    return kayttotili.withdraw(summa);
}

bool Asiakas::luotonMaksu(double summa)
{
    return luottotili.deposit(summa);
}

bool Asiakas::luotonNosto(double summa)
{
    return luottotili.withdraw(summa);
}

bool Asiakas::tiliSiirto(double summa, Asiakas & vastaanottaja)
{
    if (summa > 0) {
        if (kayttotili.withdraw(summa)) { //Nostetaan rahaa
            vastaanottaja.talletus(summa); //Nosto onnistui, siirretään vastaanottajalla

            std::cout << "Pankkitili: " << nimi << " siirtaa " << summa << " " << vastaanottaja.getNimi() << ":lle" << std::endl;

            std::cout << nimi << " Pankkitili: Nosto " << summa << " tehty, saldoa jaljella " << kayttotili.getBalance() << std::endl;

            std::cout << vastaanottaja.getNimi() << " Pankkitili: talletus " << summa << " tehty" << std::endl;
            return true;
        } else {
            std::cout << "Siirto epaonnistui, ei tarpeeksi saldoa" << std::endl;
            return false;
        }
    } else {
        std::cout << "Virheellinen siirto, summa ei voi olla negatiivinen" << std::endl;
        return false;
    }
}
