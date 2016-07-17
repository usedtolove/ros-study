void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  delay(1000);
  Serial.print("cmd=upload&device_name=myLed&data=");
  Serial.print(random(1000));//send a random number
  Serial.println("&uid=doitu5678&key=1efd316bd2d47a26b44658fa0d3a0851");
}
