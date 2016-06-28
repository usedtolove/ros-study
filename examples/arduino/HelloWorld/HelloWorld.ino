/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */
/**
 * Since the arduino micro / leonardo uses USB for 
 * and its build in serial-controller both for programming and communicating, 
 * rosserial needs the information to access the device not in the for arduino 
 * usual serial way but with USB. So simply adding
 */

#define USE_USBCON

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[4] = "hi\n";

void setup()
{
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  nh.initNode();
  nh.advertise(chatter);
  delay(1000);
}

void loop()
{
  str_msg.data = hello;
  chatter.publish(&str_msg);
  nh.spinOnce();
  delay(1000);
}
