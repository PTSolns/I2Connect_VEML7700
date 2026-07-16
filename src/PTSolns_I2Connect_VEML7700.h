#ifndef PTSOLNS_I2CONNECT_VEML7700_H
#define PTSOLNS_I2CONNECT_VEML7700_H

#include <Arduino.h>
#include <Wire.h>

class PTSOLNS_I2CONNECT_VEML7700 {
public:
    static const uint8_t DEFAULT_I2C_ADDRESS = 0x10;
    static const uint32_t DEFAULT_I2C_CLOCK = 100000UL;
    
    // VEML7700 Command Registers
    static const uint8_t VEML7700_CMD_ALS_CONF = 0x00;
    static const uint8_t VEML7700_CMD_ALS_WH = 0x01;
    static const uint8_t VEML7700_CMD_ALS_WL = 0x02;
    static const uint8_t VEML7700_CMD_POWER_SAVING = 0x03;
    static const uint8_t VEML7700_CMD_ALS_DATA = 0x04;

    PTSOLNS_I2CONNECT_VEML7700();

    bool begin(TwoWire &wirePort = Wire, uint8_t i2cAddress = DEFAULT_I2C_ADDRESS, uint32_t i2cClock = DEFAULT_I2C_CLOCK);

    void setI2CAddress(uint8_t i2cAddress);
    void setI2CClock(uint32_t i2cClock);

    bool isConnected();
    bool configure(uint16_t configValue = 0x0000); // 0x0000 turns on sensor with default gain/IT

    float readLux();

private:
    TwoWire *_wire;
    uint8_t _i2cAddress;
    uint32_t _i2cClock;

    float _resolution;
};

#endif