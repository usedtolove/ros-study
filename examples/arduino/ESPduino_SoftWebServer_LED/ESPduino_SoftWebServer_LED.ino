#include <ESP8266WiFi.h>
/* 建立Wifi热点并设置一个Web服务 */
#include <ESP8266WebServer.h>

const int LED = 0; //LED Pin 脚
int operationCount = 0; //操作计数器

/*自定义AP的SSID名称和接入密码 */
const char *ssid = "EspTestAp2";
const char *password = "12345678";

/*
   声明web服务对象server和端口80
*/
ESP8266WebServer server(80);

/*在web浏览器中输入 http://192.168.4.1来连接到AP的web模式，
  这个地址是预先在头文件中定义好的，可以在其中修改 */
/*
   设定web服务的成功响应信息
*/
void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected</h1>");
}

void handleLedOn() {
  operationCount++;
  digitalWrite(LED, LOW);
  server.send(200, "text/html", "<h1>LED ON, operation Count: " + (String)operationCount + "</h1>");
}

void handleLedOff() {
  operationCount++;
  digitalWrite(LED, HIGH);
  server.send(200, "text/html", "<h1>LED OFF, operation Count: " + (String)operationCount + "</h1>");
}

void setup() {
  pinMode(LED, OUTPUT);     // Initialize LED pin as output
  digitalWrite(LED, HIGH);   //LED OFF

  Serial.begin(115200);
  delay(10);
  
  /*如果使用开放式AP模式，可以把下面语句的password参数省略 */
  WiFi.softAP(ssid, password);
  //调用on方法，给客户端发送响应信息，启动web服务，并在串口回显
  server.on("/", handleRoot);
  server.on("/led/on", handleLedOn);
  server.on("/led/off", handleLedOff);
  server.begin();
}
//循环等待处理客户端的连接
void loop() {
  server.handleClient();
}

