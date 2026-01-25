#ifndef CHEF_H
#define CHEF_H
#include <string>
using namespace std;

class Chef
{
protected:
    string ChefName;

public:
    Chef(string);
    ~Chef();
    string getName();
    int makeSalad(int items);
    int makeSoup(int items);
};

#endif // CHEF_H
