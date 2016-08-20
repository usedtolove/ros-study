#include "http.h"
#include <iostream>
#include <curl/curl.h>
#include <string.h>
using namespace std;

/**
* usage :
* 1. start hardware demo: "ESPduino_SerialWebServer_LED_DHCP"
* 2. compile and run this demo
*/
int main(int argc, char *argv[]){
	cout << "main() run..." << endl;
	Http http;
	const char *url = "http://192.168.0.125:80/gpio/0";

	if(strcmp(argv[1], "on") != 0){
		url = "http://192.168.0.125:80/gpio/1";
	}

	int res = http.get(url);
	cout << "main() end, res:" << res << endl;
	return 0;
}
