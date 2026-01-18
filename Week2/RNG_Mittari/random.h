#ifndef RANDOM_H
#define RANDOM_H

class Random
{
public:
    Random();   //konstruktori suoritetaan
                //aina kun luokasta luodaan
                //olio
    void setSeed(long long);
    long long getSeed();
    long long rand();

private:
    long long a;
    long long c;
    long long Xn;
    long long mod;
};

#endif // RANDOM_H
