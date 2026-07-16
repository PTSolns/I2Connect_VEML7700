// Example: 01_BasicLuxRead for I2Connect: VEML7700
// Last Update: July 16, 2026
// Support: http://ptsolns.com/contact-us
//
// WHAT THIS EXAMPLE DOES
// Initializes the VEML7700 sensor and reads basic ambient light data 
// to the Serial Monitor.
//
// SKILLS LEARNED
// begin()
// readLux()
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
const uint32_t SERIAL_BAUD  = 115200; // Serial baud setting
const uint32_t I2C_CLOCK_HZ = 100000; // I2C clock speed. Keep at 100 kHz most of the time.
const uint8_t  I2C_ADDRESS  = 0x10;   // Fixed address for the VEML7700 sensor

PTSOLNS_I2CONNECT_VEML7700 lightSensor;

void setup() {
    Serial.begin(SERIAL_BAUD);
    while (!Serial) { }

    Wire.begin();
    
    if (!lightSensor.begin(Wire, I2C_ADDRESS, I2C_CLOCK_HZ)) {
        Serial.println("VEML7700 not detected. Please check your wiring!");
        while (1) { } // Halt execution
    }
    
    Serial.println("VEML7700 detected and initialized.");
    Serial.println("--------------------------------");
}

void loop() {
    float currentLux = lightSensor.readLux();
    
    if (currentLux >= 0.0) {
        Serial.print("Ambient Light: ");
        Serial.print(currentLux);
        Serial.println(" lx");
    } else {
        Serial.println("Failed to read sensor data.");
    }
    
    delay(1000); // Wait 1 second between measurements
}
