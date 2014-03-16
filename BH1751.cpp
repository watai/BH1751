#include "BH1751.h"

 void BH1751::setup(uint8_t mode)
{
  write(mode);
}

void BH1751::write(int cmd)
{
  Wire.beginTransmission(BH1751_Address);
  Wire.write(cmd);
  Wire.endTransmission();
}

unsigned short BH1751::GetLuminance(void)
{
  return (unsigned short)read();
}

uint16_t BH1751::read()
{
    uint16_t val = 0;
	  int dataNum =0;
	  uint8_t buff[2];

  	Wire.beginTransmission(BH1751_Address);
  	Wire.requestFrom(BH1751_Address, 2);
  	while(Wire.available())
  	{
    	buff[dataNum] = Wire.read();
    	dataNum++;
  	}
  	Wire.endTransmission();

    if(dataNum==2) {
      val=(unsigned int)(((buff[0]<<8)|buff[1])/1.2+0.5);
    }

    return val;
}
