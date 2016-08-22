QT += qml quick widgets

#avoid error : "undefined reference to curl_easy_init..."
LIBS += -lcurl

CONFIG += c++11

SOURCES += main.cpp \
    http.cpp \
    led.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    http.h \
    led.h
