#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>

#include "MyClass.h"

int main(int argc, char *argv[])
{    
    QGuiApplication app(argc, argv);    
    QQmlApplicationEngine engine;

    //init type
    MyClass myClass;
    //set to root context
    QQmlContext *context = engine.rootContext();

    context->setContextProperty("myClass", &myClass);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
