#ifndef HTTP_H_
#define HTTP_H_

#include <curl/curl.h>

class Http
{
public:
	//create
	Http();
	//destory
	// ~Http();
	int get(const char *url);
private:
	//declare CURL
	CURL *curl; 
	//declare CURLcode
	CURLcode response; 
};

#endif //HTTP_H_
