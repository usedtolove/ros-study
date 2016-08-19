#include <iostream>
// #include <netdb.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define IP "192.168.0.125"
#define PORT 80

int main(int argc, char const *argv[])
{
	cout << "program start..." << endl;

	int client;
	
	//init socket client
	if((client = socket(AF_INET, SOCK_STREAM, 0)) == -1) {  
        perror("socket init error...");
        exit(1);  
    } 
	
	//init sockaddr_in
	struct sockaddr_in servaddr; //define in <netdb.h>
	memset(&servaddr, 0, sizeof(servaddr)); //define in <memory.h>
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	// servaddr.sin_addr.s_addr = inet_addr(IP); //define in <arpa/inet.h>

	//connet to socket server
	int connStatus = connect(client, (struct sockaddr *)&servaddr, sizeof(struct sockaddr));
	// cout << "connStatus:" << connStatus << endl;
	if(connStatus < 0){
		perror("connect failed...");  
        exit(1);  
	}

	cout << "connect success" << endl;

	cout << "program end..." << endl;
	return 0;
}
