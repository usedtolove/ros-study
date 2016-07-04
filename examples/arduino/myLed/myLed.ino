#define Pot A0
#define LED 3
//const int sensor = A0;
//const int led = 3;

int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(Pot);
  //映射上下限范围
  sensorValue = map(sensorValue, 0, 1023, 0, 255);

  analogWrite(LED, sensorValue);
}
