/**
   使用 WIFI 扩展板 控制 LED 开关
*/

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readString();
    if (data == "on") {
      digitalWrite(2, HIGH);
    } else if (data == "off") {
      digitalWrite(2, LOW);
    } else {
      digitalWrite(2, HIGH);
      delay(1000);+
      digitalWrite(2, LOW);
    }
  }
}
