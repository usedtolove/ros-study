/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
*/

#define LED 3
#define SoundSensor 6

int val = 1;

int timeStart = 0;
int timeCurrent = 0;

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  pinMode(SoundSensor, INPUT);
}

void loop() {
  val = digitalRead(SoundSensor);
  if (val == 0) {

    timeStart = millis();

    //double check
    while (true) {
      timeCurrent = millis();
      if ((timeCurrent - timeStart) > 1000) {
        break;
      }

      val = digitalRead(SoundSensor);
      if (val == 0) {
        digitalWrite(LED, LOW);
        delay(1000 * 10);
      }
    }
  } else {
    //    Serial.println("LED off");
    digitalWrite(LED, HIGH);
  }
}
