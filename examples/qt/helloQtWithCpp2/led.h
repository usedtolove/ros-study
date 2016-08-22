#ifndef LED_H
#define LED_H

#include <QObject>
#include "http.h"

class Led : public QObject
{
    Q_OBJECT
public:
    Led();
public slots:
    void on();
    void off();
private :
    Http http;
};

#endif // LED_H
