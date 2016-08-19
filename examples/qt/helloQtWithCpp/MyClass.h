#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
public:
    MyClass();

public slots:
    void myFun();
};

#endif //MYCLASS_H
