#include "luottotili.h"
#include <iostream>

Luottotili::Luottotili(std::string s, double raja) : Pankkitili(s)
{
    luottoraja = raja;
}

bool Luottotili::deposit(double summa)
{
    if (summa > 0) {        //maksun on oltava positiivinen
        saldo += summa;     //lisää summan saldoon (velanmaksu)
        if (saldo > 0) {    //Jos saldo on yli 0 saldo = 0 koska luottotilin saldo ei saa olla yli 0 (tehtävän ohjeiden mukaan, vaikka esimerkkitulostuksessa saldo näytti 1000)
            saldo = 0;
        }
        std::cout << "Luottotilin velanmaksu: " << summa << " tehty, saldo nyt " << saldo << std::endl;
        return true;
    } else {
        std::cout << "Pankkitili: virhe, velanmaksu ei voi olla negatiivinen" << std::endl;
        return false;
    }
}

bool Luottotili::withdraw(double summa)
{
    if (summa > 0 && saldo - summa >= -luottoraja) {    //Nostettava summa on positiivinen ja ei alle luottorajan.
        saldo -= summa;       //Vähennetään summa saldosta -> saldo menee negatiiviseksi
        std::cout << "Luottotili: nosto " << summa << " tehty, luottoa jaljella " << (luottoraja + saldo) << std::endl;
        return true;
    }   else if (summa <= 0) {
        std::cout << "Nosto epaonnistui, noston täytyy olla positiivinen" << std::endl;
        return false;
    } else {
        std::cout << "Nosto epaonnistui, saldo ei riita" << std::endl;
        return false;
    }
}

double Luottotili::nostettavissa()
{
    return luottoraja + saldo;
}
