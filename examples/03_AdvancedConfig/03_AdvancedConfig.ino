// Example: 03_AdvancedConfig for I2Connect: VEML7700
// Last Update: July 16, 2026
// Support: http://ptsolns.com/contact-us
//
// WHAT THIS EXAMPLE DOES
// Demonstrates how to write custom configuration values to the VEML7700 
// to manually adjust gain or integration times for specific environments.
//
// SKILLS LEARNED
// configure()
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
const uint32_t SERIAL_BAUD  = 115200; 
const uint32_t I2C_CLOCK_HZ = 100000; 
const uint8_t  I2C_ADDRESS  = 0x10;   

PTSOLNS_I2CONNECT_VEML7700 lightSensor;

void setup() {
    Serial.begin(SERIAL_BAUD);
    while (!Serial) { }

    Wire.begin();
    
    if (!lightSensor.begin(Wire, I2C_ADDRESS, I2C_CLOCK_HZ)) {
        Serial.println("VEML7700 not detected.");
        while (1) { } 
    }
    
    Serial.println("VEML7700 initialized.");

    // The configure() function accepts a 16-bit register value.
    // 0x0000 is the default run mode (Gain 1/8, IT 100ms).
    // Modifying this allows you to tweak the sensor for very bright
    // or very dark environments. See the VEML7700 datasheet for bitmath.
    
    uint16_t customConfig = 0x0000; 
    
    if (lightSensor.configure(customConfig)) {
        Serial.println("Custom configuration applied successfully.");
    } else {
        Serial.println("Failed to apply custom configuration.");
    }
    
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
    
    delay(1000); 
}
