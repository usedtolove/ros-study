#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <QObject>
#include <iostream>
using namespace std;

#include "led.h"

int main(int argc, char *argv[])
{    
    QGuiApplication app(argc, argv);    
    QQmlApplicationEngine engine;

    //init type
    Led led;

    //set to root context
    QQmlContext *context = engine.rootContext();

    context->setContextProperty("led", &led);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
