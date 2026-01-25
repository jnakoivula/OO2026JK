#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main()
{
    Chef chef("Gordon");

    chef.makeSalad(11);
    chef.makeSoup(14);

    cout << endl;

    ItalianChef italianChef("Gino");
    italianChef.makeSalad(9);
    italianChef.askSecret("pizza", 12, 12);

    //Tested password with user input
    /*
    string userPassword;
    cout << "Enter password: ";
    cin >> userPassword;

    italianChef.askSecret(userPassword, 12, 12);
    */
    return 0;
}

