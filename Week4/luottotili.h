#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"
#include <string>

class Luottotili : public Pankkitili
{
protected:
    double luottoraja = 0;
public:
    Luottotili(std::string, double);
    bool deposit(double) override;
    bool withdraw(double) override;
    double nostettavissa(); //Selkeyttää käyttäjälle luoton määrää sillä saldo
                            // ei saanut olla yli 0 tehtävän mukaan
};

#endif // LUOTTOTILI_H
