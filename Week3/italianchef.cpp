#include "italianchef.h"
#include <iostream>
#include <algorithm>

using namespace std;


ItalianChef::ItalianChef(string name) : Chef(name)
{
    cout << "ItalianChef " << ChefName << " constructor enabled" << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "ItalianChef " << ChefName << " destructor enabled" << endl;
}

bool ItalianChef::askSecret(string guess, int a, int b)
{
    if (guess.compare(password) == 0) {
        cout << "Password ok!" << endl;
        makePizza (a,b);
        return true;
    } else {
        cout << "Password false!" << endl;
        return false;
    }
}

int ItalianChef::makePizza(int numOfFlour, int numOfWater)
{
    flour = numOfFlour;
    water = numOfWater;

    int pizzaF = flour / 5;
    int pizzaW = water / 5;
    int pizzas = min(pizzaF, pizzaW);

    cout << "ItalianChef " << ChefName << " with " << flour << " flour and " << water << " water can make " << pizzas << " pizzas" << endl;
    return pizzas;
}
