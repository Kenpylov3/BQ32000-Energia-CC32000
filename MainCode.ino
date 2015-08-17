#include <I2cMaster.h>

#define SCL_PIN 31
#define SDA_PIN 32

unsigned char ss, mm, hh, d, m, y;

SoftI2cMaster I2C(SDA_PIN, SCL_PIN);
void setup()
{
  Serial.begin(9600);
  BQ32000_Init();
  BQ32000_SOUT1Hz();
  BQ32000_SetTime(0x10,0x010,0x10);
  BQ32000_SetDate(0x01,0x01,0x01);
}
void loop()
{
  BQ32000_GetTime(&ss,&mm,&hh);
  BQ32000_GetDate(&d,&m,&y);
  Serial.print(hh);
  Serial.print(':');
  Serial.print(mm);
  Serial.print(':');
  Serial.print(ss);
  
  Serial.print("\t");
  
  Serial.print(d);
  Serial.print('/');
  Serial.print(m);
  Serial.print("/");
  Serial.print(y+2000);
  
  Serial.println();
  delay(1000);
}
