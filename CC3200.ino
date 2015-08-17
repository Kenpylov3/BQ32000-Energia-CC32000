////////////////////////////////////////////////////////////////////
// THU VIEN READ TIME CLOCK DS1307
// VIET BOI : NGUYEN QUOC CUONG (QCN) TDH-K39 CAN THO UNIVERSITY
// Version :  1.0  16/08/2015
// Email:     cuongb1306128@student.ctu.edu.vn
// Facebook:  fb.com/kenpylov3
// .................................................................
// Energia, Arduino LIBRARY
//******************************************************************/

#define BQ32000_Write    0xD0    // DS1307 Write Address
#define BQ32000_Read     0xD1    // Ds1307 Read Address

#define SEC_ADDRESS     0x00    // Address to access Ds1307 SEC register
#define MIN_ADDRESS     0x01    // Address to access Ds1307 MIN register
#define HOUR_ADDRESS    0x02    // Address to access Ds1307 HOUR register

#define DATE_ADDRESS    0x04    // Address to access Ds1307 DATE register
#define MONTH_ADDRESS   0x05    // Address to access Ds1307 MONTH register
#define YEAR_ADDRESS    0x06    // Address to access Ds1307 YEAR register

#define RAM_ADDRESS     0x08  // Address to access DS1307 RAM
#define CONTROL         0x07    // Address to access Ds1307 CONTROL register



/*--------------------------------------------------------------------------------*/
void BQ32000_Init(){
/*--------------------------------------------------------------------------------*/
 I2C.start(BQ32000_Write);
 
 I2C.write(CONTROL);
 I2C.write(0x10);     //anable SOUT
 I2C.stop();
}
/*--------------------------------------------------------------------------------*/
void BQ32000_SetTime(unsigned char _hour,  unsigned char _min,  unsigned char _sec){
/*--------------------------------------------------------------------------------*/
 I2C.start(BQ32000_Write);
 I2C.write(SEC_ADDRESS);
 I2C.write(_sec);
 I2C.write(_min);
 I2C.write(_hour);
 
 I2C.stop();
}

/*--------------------------------------------------------------------------------*/
void BQ32000_SetDate(unsigned char _date,  unsigned char _month,  unsigned char _year){
/*--------------------------------------------------------------------------------*/
 I2C.start(BQ32000_Write);
 I2C.write(DATE_ADDRESS);
 I2C.write(_date);
 I2C.write(_month);
 I2C.write(_year);
 
 I2C.stop();
}

/*--------------------------------------------------------------------------------*/
void BQ32000_GetTime(unsigned char *_sec,  unsigned char *_min,  unsigned char *_hour){
/*--------------------------------------------------------------------------------*/
 I2C.start(BQ32000_Write);
 I2C.write(SEC_ADDRESS);
 I2C.stop();
 
 I2C.restart(BQ32000_Read);
 *_sec = I2C.read(0);
 *_min = I2C.read(0);
 *_hour= I2C.read(1);
 
 *_sec  =  ((*_sec  >>4) & 0x0f)*10 + (*_sec  & 0x0f);
 *_min  =  ((*_min  >>4) & 0x0f)*10 + (*_min  & 0x0f);
 *_hour =  ((*_hour >>4) & 0x0f)*10 + (*_hour & 0x0f);
 
 I2C.stop();
}

/*--------------------------------------------------------------------------------*/
void BQ32000_GetDate(unsigned char *_day,  unsigned char *_month,  unsigned char *_year){
/*--------------------------------------------------------------------------------*/
 I2C.start(BQ32000_Write);
 I2C.write(DATE_ADDRESS);
 I2C.stop();
 
 I2C.restart(BQ32000_Read);
 *_day   = I2C.read(0);
 *_month = I2C.read(0);
 *_year  = I2C.read(1);
 
 *_day  =  ((*_day   >>4) & 0x0f)*10 + (*_day   & 0x0f);
 *_month=  ((*_month >>4) & 0x0f)*10 + (*_month & 0x0f);
 *_year =  ((*_year  >>4) & 0x0f)*10 + (*_year  & 0x0f); 
 
 I2C.stop();
}

/*--------------------------------------------------------------------------------*/
void BQ32000_SOUT1Hz(){
/*--------------------------------------------------------------------------------*/
  I2C.start(BQ32000_Write);
  I2C.write(0x07);
  I2C.write(0x40);
  I2C.restart(BQ32000_Write);
  I2C.write(0x20);
  I2C.write(0x5e);
  I2C.restart(BQ32000_Write);
  I2C.write(0x21);
  I2C.write(0xc7);
  I2C.restart(BQ32000_Write);
  I2C.write(0x22);
  I2C.write(0x01);
  I2C.stop();
}
