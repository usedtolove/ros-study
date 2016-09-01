// ArduCAM demo (C)2015 Lee
// web: http://www.ArduCAM.com
// This program is a demo of how to use most of the functions
// of the library with a supported camera modules, and can run on any Arduino platform.
//
// This demo was made for Omnivision OV2640 2MP sensor.
// It will run the ArduCAM Mini 2MP as a real 2MP digital camera, provide both JPEG capture.
// The demo sketch will do the following tasks:
// 1. Set the sensor to JPEG mode.
// 2. Capture and buffer the image to FIFO every 5 seconds
// 3. Store the image to Micro SD/TF card with JPEG format in sequential.
// 4. Resolution can be changed by myCAM.set_JPEG_size() function.
// This program requires the ArduCAM V3.4.0 (or later) library and ArduCAM Mini 2MP shield
// and use Arduino IDE 1.5.2 compiler or above

#include <SD.h>
#include <Wire.h>
#include <ArduCAM.h>
#include <SPI.h>
#include "memorysaver.h"


#define SD_CS 5
#define CAM_CS 10
//const int CAM_CS = 10;

//定义摄像头 OV2640 和使用的 CS
ArduCAM myCAM(OV2640, CAM_CS);

void setup()
{
  uint8_t vid, pid;
  uint8_t temp;
  
  Wire.begin();
  
  Serial.begin(115200); //启动串口
  Serial.println("ArduCAM Start!"); //输出调试信息
  pinMode(CAM_CS, OUTPUT); // set the SPI_CS as an output:

  // initialize SPI:
  SPI.begin();
  //检查摄像头 SPI 总线正常
  myCAM.write_reg(ARDUCHIP_TEST1, 0x55);
  temp = myCAM.read_reg(ARDUCHIP_TEST1);
  if (temp != 0x55)
  {
    Serial.println("SPI interface Error!");
    while (1);
  }

  //检查摄像头模块类型为 OV2640
  myCAM.rdSensorReg8_8(OV2640_CHIPID_HIGH, &vid);
  myCAM.rdSensorReg8_8(OV2640_CHIPID_LOW, &pid);
  if ((vid != 0x26) || (pid != 0x42))
    Serial.println("Can't find OV2640 module!");
  else
    Serial.println("OV2640 detected");

  //Change to BMP capture mode and initialize the OV2640 module
  myCAM.set_format(JPEG);

  myCAM.InitCAM();
  myCAM.OV2640_set_JPEG_size(OV2640_640x480);
  //myCAM.OV2640_set_JPEG_size(OV2640_1600x1200);

  //Initialize SD Card
  if (!SD.begin(SD_CS))
  {
    Serial.println("SD Card Error");
    return;
  }
  Serial.println("SD Card detected!");

  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}


void loop()
{
  char str[8];
  File outFile;
  byte buf[256];
  static int i = 0;
  static int k = 0;
  static int n = 0;
  uint8_t temp, temp_last;
  uint8_t start_capture = 0;
  int total_time = 0;
  ////////////////////////////////

  start_capture = 1; //init capture count
  delay(5000);

  if (start_capture)
  {
    //Flush the FIFO
    myCAM.flush_fifo();
    //Clear the capture done flag
    myCAM.clear_fifo_flag();
    //Start capture
    myCAM.start_capture();
    Serial.println("Start Capture");
  }

  while (!myCAM.get_bit(ARDUCHIP_TRIG , CAP_DONE_MASK));


  Serial.println("Capture Done!");

  //Construct a file name
  k = k + 1;
  itoa(k, str, 10); //int to string
  strcat(str, ".jpg"); //concat suffix
  //Open the new file
  outFile = SD.open(str, O_WRITE | O_CREAT | O_TRUNC);
  if (! outFile)
  {
    Serial.println("open file failed");
    return;
  }
  total_time = millis();
  i = 0;
  myCAM.CS_LOW();
  myCAM.set_fifo_burst();
  temp = SPI.transfer(0x00);
  //
  //Read JPEG data from FIFO
  while ( (temp != 0xD9) | (temp_last != 0xFF))
  {
    temp_last = temp;
    temp = SPI.transfer(0x00);

    //Write image data to buffer if not full
    if (i < 256)
      buf[i++] = temp;
    else
    {
      //Write 256 bytes image data to file
      myCAM.CS_HIGH();
      outFile.write(buf, 256);
      i = 0;
      buf[i++] = temp;
      myCAM.CS_LOW();
      myCAM.set_fifo_burst();
    }
  }
  //Write the remain bytes in the buffer
  if (i > 0)
  {
    myCAM.CS_HIGH();
    outFile.write(buf, i);
  }
  //Close the file
  outFile.close();
  total_time = millis() - total_time;
  Serial.print("Total time used:");
  Serial.print(total_time, DEC);
  Serial.println(" millisecond");


  //Blink
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(250);              // wait for a second  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(250);              // wait for a second  

  
  //Clear the capture done flag
  myCAM.clear_fifo_flag();
  //Clear the start capture flag
  start_capture = 0;
}




