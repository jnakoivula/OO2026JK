#include <iostream>
//#include "random.h"
//#include <ctime>
#include "mittari.h"

using namespace std;

int main()
{
    /* Random olio;    //Tässä vaiheessa kutsuttiin
                    //luokan konstrucktori Random()
    olio.setSeed(time(0)); */

    /* DHT olio;        //Edellisiä testauksia
    olio.begin(); */
    Mittari mittari;
    mittari.setup();

    for (int i = 0; i < 10; i++) {
        mittari.mittaus();
    }
    return 0;
}
