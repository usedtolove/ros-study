/*
    This sketch demonstrates how to set up a simple "HTTP-like" server (is serial indeed).
    The server will set a GPIO pin depending on the request
      http://server_ip/gpio/0 will set the GPIO low,
      http://server_ip/gpio/1 will set the GPIO high
    server_ip is the IP get from ssid DHCP, 
    will be printed to Serial when the module is connected.
*/
#define PIN_LED 2

#include <ESP8266WiFi.h>

const char* ssid = "asd123";
const char* password = "Fm9Qm5Hu";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  // prepare pin 2
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

  // Connect to WiFi network
  Serial.println("setup() run...");
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  //尝试连接直至成功
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client (request)");
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  // Match the request
  int val;
  if (req.indexOf("/gpio/0") != -1)
    val = 0;
  else if (req.indexOf("/gpio/1") != -1)
    val = 1;
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }

  // Set GPIO2 according to the request
  digitalWrite(PIN_LED, val);

  client.flush();

  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n<h1>GPIO is now ";
  s += (val) ? "high" : "low";
  s += "</h1>\r\n</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected (request detroyed)");

  // The client will actually be disconnected
  // when the function returns and 'client' object is detroyed
}


