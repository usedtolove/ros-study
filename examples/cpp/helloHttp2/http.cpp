#include "http.h"
#include <iostream>
#include <stdio.h>
#include <curl/curl.h>
using namespace std;

Http::Http()
{
	curl = curl_easy_init();  //init CURL
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
	curl_easy_cleanup(curl);
	return response;	
}
