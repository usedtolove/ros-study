#ifndef HTTP_H
#define HTTP_H

#include <QObject>
#include <curl/curl.h>

class Http : public QObject
{
    Q_OBJECT
public:
    //create
    Http();
    //perform get request
    ~Http();
public slots:
    int get(const char *url);
private:
    //declare CURL
    CURL *curl;
    //declare CURLcode
    CURLcode response;
};

#endif // HTTP_H
