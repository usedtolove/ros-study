#include "led.h"
#include <iostream>
using namespace std;

Led::Led() : QObject()
{
    cout << "Led()..." << endl;
}

void Led::on()
{
    cout << "Led on() run..." << endl;
    const char *url = "http://192.168.0.125:80/gpio/0";
    http.get(url);
}

void Led::off()
{
    cout << "Led off() run..." << endl;
    const char *url = "http://192.168.0.125:80/gpio/1";
    http.get(url);
}

