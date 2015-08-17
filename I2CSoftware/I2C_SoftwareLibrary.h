////////////////////////////////////////////////////////////////////
// THU VIEN READ TIME CLOCK I2C Software
// VIET BOI : NGUYEN QUOC CUONG (QCN) TDH-K39 CAN THO UNIVERSITY
// Version :  1.0  16/08/2015
// Email:     cuongb1306128@student.ctu.edu.vn
// Facebook:  fb.com/kenpylov3
// .................................................................
// Energia, Arduino LIBRARY
//******************************************************************/

#ifndef I2C_MASTER_H
#define I2C_MASTER_H
#include "Energia.h"
#define BUFFER_LENGTH 16
class SoftwareWire {
public:
    SoftwareWire(uint8_t pinSDA, uint8_t pinSCL);
    void begin();
    void beginTransmission(uint8_t address);
    uint8_t endTransmission(void);
    virtual size_t write(uint8_t data);
    virtual size_t write(const uint8_t *data , size_t length);
    uint8_t requestFrom(uint8_t address, uint8_t length);
    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);
private:
    uint8_t readI2C(uint8_t last=false);
    uint8_t readI2C(uint8_t* data, uint8_t length);
    bool restartI2C(uint8_t address, uint8_t RW);
    bool startI2C(uint8_t address, uint8_t RW);
    void stopI2C();
    bool writeI2C(uint8_t data);
    bool writeI2C(uint8_t* data, size_t length);
    uint8_t _pinSDA, _pinSCL;
    static uint8_t txAddress;
    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;
    static uint8_t txBuffer[];
    static uint8_t txBufferIndex;
    static uint8_t txBufferLength;
    static uint8_t transmitting;
};
#endif
