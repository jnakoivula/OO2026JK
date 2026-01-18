#include "dht.h"
#include <iostream>
#include <ctime>
using namespace std;


void DHT::begin()
{
    cout << "DHT, begin()" << endl;
    gen.setSeed(time(0));
    cout << "gen alustettu" << endl;
}

float DHT::readTemperature()
{
    long long temp = gen.rand();
    temp = (temp%20) + 10;
    temperature = temp;
    return (float)temp;
}
