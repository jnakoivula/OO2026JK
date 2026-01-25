#include "chef.h"
#include <iostream>


Chef::Chef(string name)
{
    ChefName = name;
    cout << "Chef " << ChefName << " constructor enabled" << endl;
}

Chef::~Chef()
{
    cout << "Chef " << ChefName << " destructor enabled" << endl;
}

string Chef::getName()
{
    return ChefName;
}

int Chef::makeSalad(int items)
{
    int portions = items / 5;
    cout << "Chef " << ChefName << " with " << items  << " items can make " << portions << " salad portions" << endl;
    return portions;
}

int Chef::makeSoup(int items)
{
    int portions = items / 3;
    cout << "Chef " << ChefName << " with " << items  << " items can make " << portions << " soup portions" << endl;
    return portions;
}
