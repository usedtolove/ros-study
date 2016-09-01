#include <SD.h>
#include <Wire.h>
#include <ArduCAM.h>
#include <SPI.h>
#include "memorysaver.h"

#define SD_CS 5
// set pin 4 as the slave select for SPI:
const int SPI_CS = 10;

//定义摄像头 OV2640 和使用的 CS
ArduCAM myCAM(OV2640, SPI_CS);

void setup()
{
  uint8_t vid, pid;
  uint8_t temp;
  Wire.begin();
  Serial.begin(115200); //启动串口
  Serial.println("ArduCAM Start!"); //输出调试信息
  pinMode(SPI_CS, OUTPUT); // set the SPI_CS as an output:

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
  //myCAM.OV2640_set_JPEG_size(OV2640_640x480);
  //myCAM.OV2640_set_JPEG_size(OV2640_1600x1200);

}

void loop()
{
}





