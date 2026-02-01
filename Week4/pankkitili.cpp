#include "pankkitili.h"
#include <iostream>



Pankkitili::Pankkitili(std::string s)
{
    omistaja = s;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double summa)
{
    if (summa > 0) { // summan on oltava positiivinen
        saldo += summa;

        std::cout << "Pankkitili: talletus " << summa << " tehty" << std::endl;
        return true;
    } else {

        std::cout << "Pankkitili: virhe, talletus ei voi olla negatiivinen" << std::endl;
        return false;
    }
}

bool Pankkitili::withdraw(double summa)
{
    if (summa > 0 && summa <= saldo) { // summa on positiivinen ja pienempi tai yhtäsuuri kuin saldo
        saldo -= summa; // vähennetään summa saldosta

        //std::cout << "Nosto " << summa << " tehty, saldoa jaljella " << saldo << std::endl;
        return true;
    } else if (summa <= 0) {

        std::cout << "Nosto epaonnistui, noston täytyy olla positiivinen" << std::endl;
        return false;
    } else {

        std::cout << "Nosto epaonnistui, saldo ei riita" << std::endl;
        return false;
    }
}
