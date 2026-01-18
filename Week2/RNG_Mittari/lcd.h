#ifndef LCD_H
#define LCD_H
#include <string>
using namespace std;

class LCD
{
public:
    void begin();
    void print(string);
    string floatToString(float);

private:
    string text;

};

#endif // LCD_H
