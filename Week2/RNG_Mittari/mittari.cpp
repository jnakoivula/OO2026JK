#include "mittari.h"
#include <iostream>

using namespace std;

void Mittari::setup()
{
    cout << "Mittari setup()" << endl;

    varoitusvalo = 0;
    lcdOlio.begin();
    dhtOlio.begin();

    cout << "Mittari alustettu" << endl;
}

void Mittari::mittaus()
{
    cout << "Mittari mittaus()"  << endl;

    float temp = dhtOlio.readTemperature();
    string tempString = lcdOlio.floatToString(temp);

    lcdOlio.print("Lämpötila: " + tempString);

    if (temp >= 27) { //Varoitusvalolle jotain tekemistä
        varoitusvalo = 1;
    }
    else {
        varoitusvalo = 0;
    }
}
