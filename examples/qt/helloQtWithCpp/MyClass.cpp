#include <QObject>
#include "MyClass.h"

MyClass::MyClass() : QObject()
{
    qDebug("MyClass constructor run...");
}

void MyClass::myFun()
{
    qDebug("MyClass myFun() run...");
}
