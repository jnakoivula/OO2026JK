#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <string>

class Pankkitili
{
protected:
    std::string omistaja;
    double saldo = 0;
public:
    Pankkitili(std::string);
    double getBalance();
    virtual bool deposit(double);
    virtual bool withdraw(double);
};

#endif // PANKKITILI_H
