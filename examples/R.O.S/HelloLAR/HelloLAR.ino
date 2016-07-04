/**
   HelloWorld Lego-Arduino-ROS
   用 Arduino 控制 Lego EV3 中型马达
*/

#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <BricktronicsShield.h>
#include <Encoder.h>
#include <PID_v1.h>
#include <BricktronicsMotor.h>

long timeout = 0;

/**
   Create the motor1 object,
   correspond to the motors plugged into Motor Port 1 of the Bricktronics Shield.
*/
BricktronicsMotor m(BricktronicsShield::MOTOR_1);

boolean forward = false;

/**
   The setup() function is called once, on power on.
   Here, it’s used to initialize all the Bricktronics objects.
*/
void setup()
{
  Serial.begin(115200);
  BricktronicsShield::begin(); //begin BricktronicsShield
  m.begin(); //begin motor1
}

void loop() // In Arduino, your loop() function is called over and over again, until the Arduino runs out of power.
{
  if (forward) {
    Serial.println("Going forward.");
    m.setFixedDrive(255);
  } else {
    Serial.println("Going in reverse.");
    m.setFixedDrive(-255);
  }
  delay(2000);

  //Stop the motor and hold it in place
  m.hold();
  delay(1000);

  forward = !forward;
  delay(100);
}

