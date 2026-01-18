#include "random.h"

Random::Random() {
    a = 1664525;
    c = 1013904223;
    Xn = 0; //seed number
    mod = 4294967296;

}

void Random::setSeed(long long s)
{
    Xn = s;
}

long long Random::getSeed()
{
    return Xn;
}

long long Random::rand()
{
    long long tulos = ((a*Xn)+c)%mod;
    Xn = tulos;
    return Xn;
}
