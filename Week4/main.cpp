#include <iostream>
#include "asiakas.h"

int main()
{
    Asiakas asiakas("Joonas", 1000);
    asiakas.showSaldo();

    std::cout << "\n";

    asiakas.talletus(250);
    asiakas.luotonNosto(150);
    asiakas.showSaldo();

    std::cout << "\n";

    Asiakas asiakas2("Bertta", 1000);
    asiakas2.showSaldo();

    std::cout << "\n";

    std::cout << asiakas.getNimi() << std::endl;
    asiakas.showSaldo();
    asiakas.tiliSiirto(50, asiakas2);

    std::cout << "\n";

    std::cout << asiakas2.getNimi() << std::endl;
    asiakas2.showSaldo();
    return 0;
}
