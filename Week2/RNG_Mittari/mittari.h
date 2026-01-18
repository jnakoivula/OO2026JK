#ifndef MITTARI_H
#define MITTARI_H

#include "lcd.h"
#include "dht.h"

class Mittari
{
public:
    void setup();
    void mittaus();

private:
    int varoitusvalo;
    LCD lcdOlio;
    DHT dhtOlio;
};

#endif // MITTARI_H
