// Example: 02_SensorDetection for I2Connect: VEML7700
// Last Update: July 16, 2026
// Support: http://ptsolns.com/contact-us
//
// WHAT THIS EXAMPLE DOES
// Continuously checks the I2C bus to verify if the VEML7700 sensor is 
// properly connected and responding to its fixed address.
//
// SKILLS LEARNED
// isConnected()
//
// DESCRIPTION
// The I2Connect: VEML7700 is a compact ambient light sensing module 
// based on the VEML7700 digital sensor. It provides a simple and reliable way 
// to add light sensing capabilities to embedded systems.
// The module communicates over the standard I2C interface with a fixed address 
// of 0x10. If multiple VEML7700 modules are required in the same system, an I2C 
// multiplexer must be used.
// Like all I2Connect modules, it features dual Qwiic compatible connectors for 
// easy daisy-chaining and an angled male header for breadboard use. It is 
// fully compatible with both 3.3V and 5V microcontroller systems.

#include <Wire.h>
#include "PTSOLNS_I2CONNECT_VEML7700.h"

// User Settings
const uint32_t SERIAL_BAUD  = 115200; 
const uint8_t  I2C_ADDRESS  = 0x10;

PTSOLNS_I2CONNECT_VEML7700 lightSensor;

void setup() {
    Serial.begin(SERIAL_BAUD);
    while (!Serial) { }

    Wire.begin();
    
    // Set the address so the library knows where to look
    lightSensor.setI2CAddress(I2C_ADDRESS);

    Serial.println("Starting Sensor Detection...");
    Serial.println("--------------------------------");
}

void loop() {
    if (lightSensor.isConnected()) {
        Serial.println("Status: VEML7700 DETECTED at address 0x10");
    } else {
        Serial.println("Status: VEML7700 NOT DETECTED. Check wiring or power.");
    }
    
    delay(2000); // Ping the bus every 2 seconds
}
