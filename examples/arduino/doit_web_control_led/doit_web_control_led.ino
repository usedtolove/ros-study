
boolean flag = true;
String comdata = "";

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  delay(1000);
  //先订阅自己的用户 uid = doitu5678
  Serial.println("cmd=subscribe&topic=doitu5678");
  delay(1000);
}

void loop() {
  if (Serial.available() > 0) {
    comdata += char(Serial.read());
    delay(100);
  }

  if (comdata.length() > 0) {
    //设备得到命令
    if (comdata.compareTo("cmd=publish&device_name=myLed&device_cmd=on\r\n") == 0) {
      digitalWrite(2, LOW);
    } else if (comdata.compareTo("cmd=publish&device_name=myLed&device_cmd=off\r\n") == 0) {
      digitalWrite(2, HIGH);
    }
    comdata = "";
  } else {
    Serial.println("nothing...");
  }

  delay(1000);
}
