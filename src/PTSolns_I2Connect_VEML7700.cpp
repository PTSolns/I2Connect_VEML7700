#include "PTSOLNS_I2CONNECT_VEML7700.h"

PTSOLNS_I2CONNECT_VEML7700::PTSOLNS_I2CONNECT_VEML7700() {
    _wire = &Wire;
    _i2cAddress = DEFAULT_I2C_ADDRESS;
    _i2cClock = DEFAULT_I2C_CLOCK;
    _resolution = 0.0573; // Default resolution for Gain=1/8, IT=100ms
}

bool PTSOLNS_I2CONNECT_VEML7700::begin(TwoWire &wirePort, uint8_t i2cAddress, uint32_t i2cClock) {
    _wire = &wirePort;
    setI2CAddress(i2cAddress); 
    _i2cClock = i2cClock;
    _wire->setClock(_i2cClock);

    delay(40); 

    if (!isConnected()) {
        return false;
    }

    // Initialize sensor with default configuration (Power on)
    if (!configure(0x0000)) {
        return false;
    }
    
    delay(10); // Wait for sensor to stabilize
    return true;
}

void PTSOLNS_I2CONNECT_VEML7700::setI2CAddress(uint8_t i2cAddress) {
    _i2cAddress = i2cAddress;
}

void PTSOLNS_I2CONNECT_VEML7700::setI2CClock(uint32_t i2cClock) {
    _i2cClock = i2cClock;
    if (_wire) {
        _wire->setClock(_i2cClock);
    }
}

bool PTSOLNS_I2CONNECT_VEML7700::isConnected() {
    _wire->beginTransmission(_i2cAddress);
    return (_wire->endTransmission() == 0);
}

bool PTSOLNS_I2CONNECT_VEML7700::configure(uint16_t configValue) {
    _wire->beginTransmission(_i2cAddress);
    _wire->write(VEML7700_CMD_ALS_CONF);
    
    // VEML7700 expects LSB first, then MSB
    _wire->write(configValue & 0xFF);
    _wire->write(configValue >> 8);
    
    return (_wire->endTransmission() == 0);
}

float PTSOLNS_I2CONNECT_VEML7700::readLux() {
    _wire->beginTransmission(_i2cAddress);
    _wire->write(VEML7700_CMD_ALS_DATA);
    
    if (_wire->endTransmission(false) != 0) {
        return -1.0; // Communication error
    }

    uint8_t received = _wire->requestFrom(_i2cAddress, (uint8_t)2);
    
    if (received != 2) {
        return -1.0; // Failed to receive data
    }

    uint16_t rawData = _wire->read();
    rawData |= (_wire->read() << 8); // LSB first, then MSB

    return (float)rawData * _resolution;
}