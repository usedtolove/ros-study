#include <iostream>
#include <stdio.h>
#include <curl/curl.h>

using namespace std;

/**
* usage :
* 1. start hardware demo: "ESPduino_SerialWebServer_LED_DHCP"
* 2. compile this source: g++ helloHttp.cpp -o helloHttp -lcurl
* 3. send request:
* ./helloHttp http://192.168.0.125:80/gpio/0 turn on led
* ./helloHttp http://192.168.0.125:80/gpio/1 turn off led
*/
int main(int argc, char *argv[]){

	CURL *curl; //declare CURL
	CURLcode response; //declare CURLcode

	curl = curl_easy_init();  //init CURL

	if(!curl){
		cout << "CURL init error..." << endl;
	}else{
		//curl_easy_setopt(curl, CURLOPT_URL, "http://192.168.0.125:80/gpio/1");
		curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
		//perform request
		response = curl_easy_perform(curl);
		//print response
		cout << "response:" << response << endl;
		//cleanup CURL opt
        curl_easy_cleanup(curl);
		return 0;
	}
}
