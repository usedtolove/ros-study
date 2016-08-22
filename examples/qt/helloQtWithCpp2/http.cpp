#include "http.h"
#include <iostream>
#include <stdio.h>

#define CURL_STATICLIB
#include <curl/curl.h>
//#include <curl/easy.h>
using namespace std;

Http::Http() : QObject()
{
    curl = curl_easy_init();  //init CURL
}

Http::~Http()
{
    curl_easy_cleanup(curl);
}

int Http::get(const char *url)
{
    if(!curl){
        cout << "CURL init error..." << endl;
        return -1;
    }

    cout << "url:" << url << endl;
    cout << "CURL init success..." << endl;

    curl_easy_setopt(curl, CURLOPT_URL, url);
    response = curl_easy_perform(curl);

    cout << "response:" << response << endl;

    return response;
}
