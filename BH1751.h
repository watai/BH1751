/*
This is a arduino library for the BH1751FVI Digital Light Sensor.
The Sensor uses I2C for communication. 2 pins are required to
interface to the device.

Datasheet:
http://rohmfs.rohm.com/jp/products/databook/datasheet/ic/sensor/light/bh1751fvi-j.pdf

Created by Taiki Watai, Sep 2013.
*/

#ifndef BH1751_H
#define BH1751_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
#include <Wire.h>
#include <math.h>

#define M_H_RESOLUTION_MODE   0x10     // H-Resolution Mode:  0b00010000
#define M_H_RESOLUTION_MODE2  0x11     // H-Resolution Mode2: 0b00010001
#define M_L_RESOLUTION_MODE   0x13     // L-Resolution Mode:  0b00010011
#define S_H_RESOLUTION_MODE   0x20     // H-Resolution Mode:  0b00100000
#define S_H_RESOLUTION_MODE2  0x21     // H-Resolution Mode2: 0b00100001
#define S_L_RESOLUTION_MODE   0x23     // L-Resolution Mode:  0b00100011
#define BH1751_Address 0x23 

class BH1751
{
  public:
 	void setup(uint8_t mode);
 	unsigned short GetLuminance(void);
  private:
  	uint16_t read();
  	void write(int cmd);
};
#endif
